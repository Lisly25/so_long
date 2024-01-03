/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:43 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 10:24:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map(t_vector *map)
{
	if (check_char_num(map->map) == 0)
		return (1);
	if (check_chars(map->map) == 1)
		return (1);
	if (is_rectangle(map->map) == 1)
		return (1);
	if (is_walled(map->map) == 1)
		return (ft_error_message("Error\nMap must be surrounded by walls\n"));
	if (check_path(map) == 1)
		return (ft_error_message("Error\nNo valid path through map\n"));
	return (0);
}

int	validate_map(char *map_path)
{
	t_vector	*map;
	int			result;

	map = read_map(map_path);
	if (map->map[0] == NULL)
		ft_error("Error\nMap could not be read");
	result = check_map(map);
	free_map(map);
	return (result);
}
