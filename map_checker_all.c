/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:43 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/05 15:20:55 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_name(char *map_path)
{
	size_t	len;

	len = ft_strlen(map_path);
	map_path = map_path + (len - 4);
	if (ft_strncmp(map_path, ".ber", 4) != 0)
		return (1);
	return (0);
}

static int	check_map(t_vector *map)
{
	if (check_char_num(map->map) == 1)
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

	if (check_file_name(map_path) == 1)
	{
		ft_error_message("Error\nMap file must have .ber extension\n");
		exit (1);
	}
	map = read_map(map_path);
	if (map->map[0] == NULL)
		ft_error("Error\nMap could not be read");
	result = check_map(map);
	free_map(map);
	return (result);
}
