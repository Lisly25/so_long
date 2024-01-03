/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:01:29 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 10:47:02 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_assets(t_data *data)
{
	mlx_texture_t	*cat_sitting;
	mlx_texture_t	*house;
	mlx_texture_t	*tree;
	mlx_texture_t	*ground;
	mlx_texture_t	*bird;

	cat_sitting = mlx_load_png(PLAYER_PATH);
	house = mlx_load_png(EXIT_PATH);
	tree = mlx_load_png(TREE_PATH);
	ground = mlx_load_png(GROUND_PATH);
	bird = mlx_load_png(COLLECTIBLE_PATH);
	if (!cat_sitting || !house || !tree || !ground || !bird)
		ft_mlx_error(data);
	data->player = mlx_texture_to_image(data->window, cat_sitting);
	data->exit = mlx_texture_to_image(data->window, house);
	data->tree = mlx_texture_to_image(data->window, tree);
	data->background = mlx_texture_to_image(data->window, ground);
	data->bird = mlx_texture_to_image(data->window, bird);
	if (!data->player || !data->exit || !data->tree || !data->background \
	|| !data->bird)
		ft_mlx_error(data);
	delete_textures(cat_sitting, house, tree, ground, bird);
	return ;
}

static void	resize_assets(t_data *assets, int scale)
{
	if (mlx_resize_image(assets->background, scale, scale) != true)
		ft_mlx_error(assets);
	if (mlx_resize_image(assets->exit, scale, scale) != true)
		ft_mlx_error(assets);
	if (mlx_resize_image(assets->tree, scale, scale) != true)
		ft_mlx_error(assets);
	if (mlx_resize_image(assets->bird, scale, scale) != true)
		ft_mlx_error(assets);
	if (mlx_resize_image(assets->player, scale, scale) != true)
		ft_mlx_error(assets);
}

t_data	*init_window(char *map_path)
{
	t_data		*ptr_to_data;
	size_t		map_height;
	size_t		map_width;

	ptr_to_data = (t_data *)malloc(sizeof(t_data));
	if (ptr_to_data == NULL)
		ft_error("Error\nMalloc fail on creating t_data struct");
	ptr_to_data->map = read_map(map_path);
	map_height = ((ptr_to_data->map->used_nodes) - 1) * SCALE;
	map_width = (ft_strlen(ptr_to_data->map->map[0]) - 1) * SCALE;
	ptr_to_data->window = mlx_init(map_width, map_height, "so_long", true);
	if (!ptr_to_data->window)
		ft_mlx_error(ptr_to_data);
	load_assets(ptr_to_data);
	resize_assets(ptr_to_data, SCALE);
	return (ptr_to_data);
}

void	ft_key_hook(mlx_key_data_t key_data, void *param)
{
	t_data		*data;
	mlx_t		*mlx;

	data = param;
	mlx = data->window;
	if (key_data.key == 256)
		key_data.key = 256;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		exit_game(data);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		move_check(data, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		move_check(data, 2);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		move_check(data, 3);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		move_check(data, 4);
}
