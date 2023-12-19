/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:17:35 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/19 15:04:57 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "vector.h"

t_vector	*read_map(void)
{
	t_vector	*map_vector;
	char		*map_line;
	int			fd;
	int			i;

	i = 0;
	map_vector = vector_new(2);
	fd = open("./map/map.ber", O_RDONLY);
	map_line = get_next_line(fd);
	vector_add_back(map_vector, map_line);
	while (map_vector->map[i] != NULL)
	{
		map_line = get_next_line(fd);
		vector_add_back(map_vector, map_line);
		i++;
	}
	close(fd);
	return (map_vector);
}
