/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:37:35 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/19 16:28:48 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static int	find_symbol(char ***map, char symbol, int is_x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_printf("\nWe entered find symbol\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	i = 0;
	while (*map[i])
	{
		while (*map[i][j] != '\n')
		{
			if (*map[i][j] == symbol)
			{
				if (is_x == 1)
				{
					ft_printf("X coordinate of start position is %d\n", j);
					return (j);
				}
				if (is_x == 0)
				{
					ft_printf("Y coordinate of start position is %d\n", i);
					return (i);
				}
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	check_move(char ***map, int x, int y)
{
	if (*map[y + 1][x] == '0' || *map[y + 1][x] == 'C' || *map[y + 1][x] == 'E')
		*map[y + 1][x] = 'X';
	if (*map[y - 1][x] == '0' || *map[y - 1][x] == 'C' || *map[y - 1][x] == 'E')
		*map[y - 1][x] = 'X';
	if (*map[y][x + 1] == '0' || *map[y][x + 1] == 'C' || *map[y][x + 1] == 'E')
		*map[y][x + 1] = 'X';
	if (*map[y][x - 1] == '0' || *map[y][x - 1] == 'C' || *map[y][x - 1] == 'E')
		*map[y][x - 1] = 'X';
	*map[x][y] = '*';
	return ;
}

static void	map_iter(char ***map, void (*f)(char ***, int, int))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*map[i])
	{
		while (*map[i][j] != '\0')
		{
			if (*map[i][j] == 'X')
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

int	check_path(char ***map)
{
	int	start_x;
	int	start_y;

	start_x = find_symbol(map, 'P', 1);
	start_y = find_symbol(map, 'P', 0);
	check_move(map, start_x, start_y);
	//just for testing
	ft_printf("Map is now\n");
	int i = 0;
	while (*map[i])
	{
		ft_printf("%s", *map[i]);
		i++;
	}
	//end of testing
	while (count_chars(*map, 'X') != 0)
	{
		map_iter(map, check_move);
	}
	if ((count_chars(*map, 'C') == 0) && (count_chars(*map, 'E') == 0))
		return (0);
	else
		return (1);
}
