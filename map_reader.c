/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:17:35 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/16 10:39:50 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

char	**read_map(void)
{
	char	**map;//I might want to later add a function to get the exact number of lines
	int		fd;
	int		i;

	map = malloc(sizeof(char *) * 30);
	i = 0;
	fd = open("./map/map.ber", O_RDONLY);
	while (map[i] != NULL)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
