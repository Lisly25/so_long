/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:52:56 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/21 15:58:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	grid_check(t_data *data, int mode)
{
	int		x;
	int		y;
	char	c;

	x = (data->player->instances[0].x) / 200;
	y = (data->player->instances[0].y) / 200;
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
	if (mode == 1)
		assets->player->instances[0].y -= 200;
	else if (mode == 2)
		assets->player->instances[0].y += 200;
	else if (mode == 3)
		assets->player->instances[0].x -= 200;
	else if (mode == 4)
		assets->player->instances[0].x += 200;
	return ;
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
		//remove the bird
	}
	if (c == 'E')
	{
		move_player(assets, mode);
		//exit game here
	}
	return ;
}
