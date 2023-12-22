/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:20:27 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 12:31:46 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_for_win(t_data *assets)
{
	int	coll_total;
	int	collected_coll;
	int	i;

	coll_total = count_chars(assets->map->map, 'C');
	i = 0;
	collected_coll = 0;
	while (i < coll_total)
	{
		if (assets->bird->instances[i].z == -1)
			collected_coll++;
		i++;
	}
	if (coll_total == collected_coll)
		return (0);
	else
		return (1);
}

void	exit_game(t_data *assets)
{
	mlx_close_window(assets->window);
}
