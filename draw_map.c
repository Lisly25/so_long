/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:38:15 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 16:36:18 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//this is a duplicate for now
static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	draw_background(t_vector *map, mlx_image_t *asset, mlx_t *mlx)
{
	size_t	i;
	size_t	j;
	int		scale;

	i = 0;
	j = 0;
	scale = SCALE;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0' && map->map[i][j] != '\n')
		{
			if (mlx_image_to_window(mlx, asset, (j * scale), (i * scale)) < 0)
				error();
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

static void	draw_asset(t_vector *map, mlx_image_t *asset, mlx_t *mlx, char c)
{
	size_t	i;
	size_t	j;
	int		scale;

	i = 0;
	j = 0;
	scale = SCALE;
	while (map->map[i] != NULL)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == c)
			{
				if (mlx_image_to_window(mlx, asset, (j * scale), (i * scale)) < 0)
					error();
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	draw_map(t_vector *map, t_data *assets)
{
	draw_background(map, assets->background, assets->window);
	draw_asset(map, assets->tree, assets->window, '1');
	draw_asset(map, assets->exit, assets->window, 'E');
	draw_asset(map, assets->bird, assets->window, 'C');
	draw_asset(map, assets->player, assets->window, 'P');
	assets->text = mlx_put_string(assets->window, "Number of moves: 0", 0, 0);
	return ;
}
