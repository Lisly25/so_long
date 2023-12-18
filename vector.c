/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:18:23 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/18 12:47:10 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_new(size_t size)
{
	t_vector	*new_vector;

	new_vector = (t_vector *)malloc(sizeof(t_vector));
	new_vector->map = (char **)malloc(size * sizeof(char *));
	new_vector->max_nodes = size;
	new_vector->used_nodes = 0;
	return (new_vector);
}

static char	**vector_array_realloc(char ***old_map, size_t node_max)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * node_max * 2);
	while (i < node_max)
	{
		new_map[i] = *old_map[i];
		i++;
	}
	free(*old_map);
	return (new_map);
}

static int	expand_vector(t_vector *old)
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
			perror("Error\nFailed to create map vector due to malloc error");
			return (1);
		}
	}
	old->map[old->used_nodes] = new_data;
	old->used_nodes++;
	return (0);
}
