/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:01:29 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 11:04:38 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
//static void ft_hook(void* param)
//{
//	const mlx_t* mlx = param;
//
//	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
//}

static void	load_assets(t_data *data)
{
	mlx_texture_t	*cat_sitting;
	mlx_texture_t	*house;
	mlx_texture_t	*tree;
	mlx_texture_t	*ground;
	mlx_texture_t	*bird;

	cat_sitting = mlx_load_png("../textures/cat/Cat_sitting.png");
	house = mlx_load_png("../textures/house/house.png");
	tree = mlx_load_png("../textures/plants/tree.png");
	ground = mlx_load_png("../textures/plants/backdrop.png");
	bird = mlx_load_png("../textures/bird/bird.png");
	if (!cat_sitting || !house || !tree || !ground || !bird)
		error();
	data->player = mlx_texture_to_image(data->window, cat_sitting);
	data->exit = mlx_texture_to_image(data->window, house);
	data->tree = mlx_texture_to_image(data->window, tree);
	data->background = mlx_texture_to_image(data->window, ground);
	data->bird = mlx_texture_to_image(data->window, bird);
	if (!data->player || !data->exit || !data->tree || !data->background \
	|| !data->bird)
        error();
	return ;
}

static t_data	*init_window(void)
{
	t_data		*ptr_to_data;
	size_t		map_height;
	size_t		map_width;

	//mlx_set_setting(MLX_MAXIMIZED, true);
	ptr_to_data = (t_data *)malloc(sizeof(t_data));
	ptr_to_data->map = read_map();
	map_height = ((ptr_to_data->map->used_nodes) - 1) * 200;
	map_width = (ft_strlen(ptr_to_data->map->map[0]) - 1) * 200;
	ptr_to_data->window = mlx_init(map_width, map_height, "Hungry Cat", true);
	if (!ptr_to_data->window)
		ft_error();
	load_assets(ptr_to_data);
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
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		move_check(data, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		move_check(data, 2);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		move_check(data, 3);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		move_check(data, 4);
}

int32_t	main(void)
{
	t_data		*data;

	data = init_window();
	//adding background
	if (mlx_resize_image(data->background, 200, 200) != true)
		error();
	//adding exit
	if (mlx_resize_image(data->exit, 200, 200) != true)
		error();
	//adding tree
	if (mlx_resize_image(data->tree, 200, 200) != true)
		error();
		//adding bird
	if (mlx_resize_image(data->bird, 200, 200) != true)
		error();
	//adding avatar
	if (mlx_resize_image(data->player, 200, 200) != true)
		error();
	draw_map(data->map, data);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_key_hook(data->window, ft_key_hook, data);
	//mlx_loop_hook(mlx, mlx_resize_hook, NULL);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	return (EXIT_SUCCESS);
}

//compile with: cc window_open.c mlx/libmlx42.a -ldl -pthread -lm -L/Users/skorbai/.brew/Cellar/glfw/3.3.8/lib -lglfw -I mlx/MLX42.h libft/libft.a map_reader.c vector.c draw_map.c
