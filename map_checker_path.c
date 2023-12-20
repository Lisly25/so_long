/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 10:37:35 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/20 14:41:02 by skorbai          ###   ########.fr       */
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
	while (i < (map->used_nodes - 1))
	{
		while (map->map[i][j] != '\0')
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

void	check_direction(t_vector *map_vector, int x, int y)
{
	char	**map;
	int		y_max;
	int		x_max;

	map = map_vector->map;
	y_max = map_vector->used_nodes;
	x_max = ft_strlen(map[0]);
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
	{
		map[y][x] = 'X';
	}
	return ;
}

void	check_move(t_vector *map_vector, int x, int y)
{
	char	**map;
	int		y_max;
	int		x_max;

	map = map_vector->map;
	y_max = map_vector->used_nodes;
	x_max = ft_strlen(map[0]);
	if ((y + 1) < y_max)
		check_direction(map_vector, x, (y + 1));
	if ((y - 1) >= 0)
		check_direction(map_vector, x, (y - 1));
	if ((x + 1) < x_max)
		check_direction(map_vector, (x + 1), y);
	if ((x - 1) >= 0)
		check_direction(map_vector, (x - 1), y);
	map[y][x] = '*';
	return ;
}

//debug function
static void	print_map(t_vector *map)
{
	size_t i = 0;

	ft_printf("\nDebugging map is:\n");
	while (i < (map->used_nodes - 1))
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	return ;
}

static void	map_iter(t_vector *map, void (*f)(t_vector *, int, int))
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < (map->used_nodes - 1))
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'X')
			{
				f(map, j, i);
				print_map(map);
				if (count_chars(map->map, 'C') == 0 && count_chars(map->map, 'E') == 0)
					return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

int	check_path(t_vector *map)
{
	int			start_x;
	int			start_y;
	int			c_count;
	int			e_count;

	start_x = find_start(map, 1);
	start_y = find_start(map, 0);
	check_move(map, start_x, start_y);
	print_map(map);
	while (count_chars(map->map, 'X') != 0)
	{
		ft_printf("X count is: %d\n", count_chars(map->map, 'X'));
		map_iter(map, check_move);
		c_count = count_chars(map->map, 'C');
		e_count = count_chars(map->map, 'E');
		if (c_count == 0 && e_count == 0)
			return (0);
	}
	ft_printf("Did we reach this?\n");
	if ((count_chars(map->map, 'C') == 0) && (count_chars(map->map, 'E') == 0))
		return (0);
	else
		return (1);
}
