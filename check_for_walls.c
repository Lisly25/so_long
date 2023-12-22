/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:56 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 16:29:34 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	grid_check(t_data *data, int mode)
{
	int		x;
	int		y;
	char	c;

	x = (data->player->instances[0].x) / SCALE;
	y = (data->player->instances[0].y) / SCALE;
	if (mode == 1)
		y--;
	else if (mode == 2)
		y++;
	else if (mode == 3)
		x--;
	else if (mode == 4)
		x++;
	c = data->map->map[y][x];
	return (c);
}

static void	move_player(t_data *assets, int mode)
{
	static int	i = 0;

	if (mode == 1)
	{
		assets->player->instances[0].y -= SCALE;
	}
	else if (mode == 2)
	{
		assets->player->instances[0].y += SCALE;
	}
	else if (mode == 3)
	{
		assets->player->instances[0].x -= SCALE;
	}
	else if (mode == 4)
	{
		assets->player->instances[0].x += SCALE;
	}
	i++;
	display_moves(assets, i, "Number of moves: ");
	return ;
}

static int	get_instance(t_data *assets, int x, int y, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = -1;
	while (assets->map->map[i] != NULL)
	{
		while (assets->map->map[i][j] != '\0')
		{
			if (assets->map->map[i][j] == c)
				count++;
			if (i == y && j == x)
				return (count);
			j++;
		}
		j = 0;
		i++;
	}
	return (-2);
}

static void	get_collectible(t_data *assets)
{
	int				i;
	int				x;
	int				y;
	mlx_instance_t	*instance;

	x = (assets->player->instances[0].x) / SCALE;
	y = (assets->player->instances[0].y) / SCALE;
	i = get_instance(assets, x, y, 'C');
	instance = &assets->bird->instances[i];
	mlx_set_instance_depth(instance, -1);
}

void	move_check(t_data *assets, int mode)
{
	char	c;

	c = grid_check(assets, mode);
	if (c == '0')
		move_player(assets, mode);
	if (c == 'P')
		move_player(assets, mode);
	if (c == '1')
		return ;
	if (c == 'C')
	{
		move_player(assets, mode);
		get_collectible(assets);
		return ;
	}
	if (c == 'E')
	{
		if (check_for_win(assets) == 1)
			move_player(assets, mode);
		else
			exit_game(assets);
	}
	return ;
}
