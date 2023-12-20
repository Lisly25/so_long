/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:43 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/20 14:51:03 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_vector *map)
{
	if (check_char_num(map->map) == 0)
		return (0);
	if (check_chars(map->map) == 1)
		return (0);
	if (is_rectangle(map->map) == 1)
		return (0);
	if (is_walled(map->map) == 1)
	{
		perror("Error\nMap must be surrounded by walls\n");
		return (0);
	}
	if (check_path(map) == 1)
	{
		perror("Error\nNo valid path through map\n");
		return (0);
	}
	return (1);
}
