/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:18:23 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 10:36:30 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "so_long.h"

t_vector	*vector_new(size_t size)
{
	t_vector	*new_vector;

	new_vector = (t_vector *)malloc(sizeof(t_vector));
	if (new_vector == NULL)
		return (NULL);
	new_vector->map = (char **)malloc(size * sizeof(char *));
	if (new_vector->map == NULL)
		return (NULL);
	new_vector->max_nodes = size;
	new_vector->used_nodes = 0;
	return (new_vector);
}

char	**vector_array_realloc(char ***old_map, size_t node_max)
{
	char	**new_map;
	size_t	i;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * node_max * 2);
	if (new_map == NULL)
		return (NULL);
	while (i < node_max)
	{
		new_map[i] = (char *)(*old_map)[i];
		i++;
	}
	free(*old_map);
	return (new_map);
}

int	expand_vector(t_vector *old)
{
	old->map = vector_array_realloc(&old->map, old->max_nodes);
	if (old->map == NULL)
	{
		return (1);
	}
	old->max_nodes *= 2;
	return (0);
}

int	vector_add_back(t_vector *old, char *new_data)
{
	if (old->used_nodes == old->max_nodes)
	{
		if (expand_vector(old) == 1)
		{
			free_map(old);
			free(new_data);
			ft_error("Error\nMap read failure (while expanding vector\n)");
		}
	}
	old->map[old->used_nodes] = new_data;
	old->used_nodes++;
	return (0);
}
