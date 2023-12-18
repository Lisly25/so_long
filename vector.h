/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:12 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/18 15:47:21 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>

typedef struct s_vector_map {
	char	**map;
	size_t	used_nodes;
	size_t	max_nodes;
}	t_vector;

t_vector	*vector_new(size_t size);

int			vector_add_back(t_vector *old, char *new_data);

char		**vector_array_realloc(char ***old_map, size_t node_max);

int			expand_vector(t_vector *old);

#endif