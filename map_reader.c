/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:17:35 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/04 14:28:08 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include "vector.h"

static void	ft_error_and_close(const char *str, int fd, t_vector *map)
{
	perror(str);
	free_map(map);
	close(fd);
	exit (EXIT_FAILURE);
}

t_vector	*read_map(char *map_path)
{
	t_vector	*map_vector;
	char		*map_line;
	int			fd;
	int			i;

	i = 0;
	map_vector = vector_new(2);
	if (map_vector == NULL)
		ft_error("Error\nFailed to create 2D vector for map\n");
	fd = open(map_path, O_RDONLY);
	map_line = get_next_line(fd);
	if (map_line == NULL)
		ft_error_and_close("Error\nFailed to read map file\n", fd, map_vector);
	vector_add_back(map_vector, map_line);
	while (map_vector->map[i++] != NULL)
	{
		map_line = get_next_line(fd);
		vector_add_back(map_vector, map_line);
	}
	close(fd);
	return (map_vector);
}
