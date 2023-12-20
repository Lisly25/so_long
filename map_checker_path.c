/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:37:35 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/20 11:33:53 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static int	find_start(t_vector *map, int is_x)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map->used_nodes)
	{
		while (map->map[i][j] != '\n')
		{
			if (map->map[i][j] == 'P')
			{
				if (is_x == 1)
					return (j);
				if (is_x == 0)
					return (i);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

void	check_move(char **map, int x, int y)
{
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
		map[y + 1][x] = 'X';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
		map[y - 1][x] = 'X';
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
		map[y][x + 1] = 'X';
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
		map[y][x - 1] = 'X';
	map[x][y] = '*';
	return ;
}

static void	map_iter(char **map, void (*f)(char **, int, int))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'X')
				f(map, j, i);
			j++;
		}
		i++;
	}
	//just for testing
	ft_printf("Map is now\n");
	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

int	check_path(t_vector *map)
{
	int			start_x;
	int			start_y;

	start_x = find_start(map, 1);
	start_y = find_start(map, 0);
	check_move(map->map, start_x, start_y);
	//just for testing
	ft_printf("Map is now\n");
	int i = 0;
	while (map->map[i])
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	//end of testing
	while (count_chars(map->map, 'X') != 0)
	{
		map_iter(map->map, check_move);
	}
	if ((count_chars(map->map, 'C') == 0) && (count_chars(map->map, 'E') == 0))
		return (0);
	else
		return (1);
}
