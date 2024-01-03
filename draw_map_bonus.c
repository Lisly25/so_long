/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:38:15 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 11:22:19 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long_bonus.h"

static void	draw_background(t_data *data)
{
	size_t	i;
	size_t	j;
	int		scale;

	i = 0;
	j = 0;
	scale = SCALE;
	while (data->map->map[i] != NULL)
	{
		while (data->map->map[i][j] != '\0' && data->map->map[i][j] != '\n')
		{
			if (mlx_image_to_window(\
			data->window, data->background, (j * scale), (i * scale)) < 0)
				ft_mlx_error(data);
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

static void	draw_asset(t_data *data, mlx_image_t *asset, char c)
{
	size_t	i;
	size_t	j;
	int		scale;

	i = 0;
	j = 0;
	scale = SCALE;
	while (data->map->map[i] != NULL)
	{
		while (data->map->map[i][j] != '\0')
		{
			if (data->map->map[i][j] == c)
			{
				if (mlx_image_to_window(\
				data->window, asset, j * scale, i * scale) < 0)
					ft_mlx_error(data);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	draw_map(t_data *assets)
{
	draw_background(assets);
	draw_asset(assets, assets->tree, '1');
	draw_asset(assets, assets->exit, 'E');
	draw_asset(assets, assets->bird, 'C');
	draw_asset(assets, assets->player, 'P');
	display_initial_moves_bonus(assets);
	return ;
}
