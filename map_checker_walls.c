/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:52:31 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 10:29:42 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

int	is_rectangle(char **map)
{
	int	i;
	int	length_first;
	int	length_rest;

	i = 0;
	length_first = ft_strlen(map[i++]);
	if (length_first == 0)
		return (ft_error_message("Error\nMust not contain empty lines\n"));
	while (map[i])
	{
		length_rest = ft_strlen(map[i]);
		if (length_rest != length_first)
		{
			if (map[i][length_rest - 1] != '\n' \
			&& length_rest == length_first - 1)
				return (0);
			return (ft_error_message("Error\nMap must be a rectangle\n"));
		}
		i++;
	}
	return (0);
}

static int	check_horizontal_wall(char *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(map);
	while (map[i] != '\0' && map[i] != '\n')
	{
		if (map[i] == '1')
			j++;
		i++;
	}
	if (map[i] == '\n' && (len == j + 1))
		return (0);
	if (map[i] == '\0' && (len == j))
		return (0);
	else
		return (1);
}

static int	check_vertical_wall(char *map)
{
	int	i;

	i = 0;
	if (map[i] != '1')
		return (1);
	while (map[i] != '\n')
		i++;
	if (map[i - 1] != '1')
		return (1);
	return (0);
}

int	is_walled(char **map)
{
	int	i;
	int	lines_num;

	i = 0;
	lines_num = 0;
	if (check_horizontal_wall(map[i++]) == 1)
		return (1);
	while (map[i])
	{
		lines_num++;
		i++;
	}
	i = 1;
	while (i < lines_num)
	{
		if (check_vertical_wall(map[i]) == 1)
			return (1);
		i++;
	}
	if (check_horizontal_wall(map[lines_num]) == 1)
		return (1);
	return (0);
}
