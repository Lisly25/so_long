/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:01:29 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/21 12:43:05 by skorbai          ###   ########.fr       */
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
	t_data	*ptr_to_data;

	mlx_set_setting(MLX_MAXIMIZED, true);
	ptr_to_data = (t_data *)malloc(sizeof(t_data));
	ptr_to_data->window = mlx_init(WIDTH, HEIGHT, "Hungry Cat", true);
	if (!ptr_to_data->window)
		ft_error();
	load_assets(ptr_to_data);
	return (ptr_to_data);
}

void ft_key_hook(void *param)
{
	t_data		*data;
	mlx_t		*mlx;
	mlx_image_t	*image;

	data = param;
	mlx = data->window;
	image = data->player;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 50;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 50;
}

int32_t	main(void)
{
	t_data	*data;

	data = init_window();
	//adding background
	if (mlx_resize_image(data->background, 200, 200) != true)
		error();
	if (mlx_image_to_window(data->window, data->background, 1200, 600) < 0)
		error();
	//adding exit
	if (mlx_resize_image(data->exit, 200, 200) != true)
		error();
	if (mlx_image_to_window(data->window, data->exit, 600, 600) < 0)
        error();
	//adding tree
	if (mlx_resize_image(data->tree, 200, 200) != true)
		error();
	if (mlx_image_to_window(data->window, data->tree, 1200, 600) < 0)
		error();
	//adding bird
	if (mlx_resize_image(data->bird, 200, 200) != true)
		error();
	if (mlx_image_to_window(data->window, data->bird, 0, 0) < 0)
		error();
	//adding avatar
	if (mlx_resize_image(data->player, 200, 200) != true)
		error();
	if (mlx_image_to_window(data->window, data->player, 0, 0) < 0)
        error();
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(data->window, ft_key_hook, data);
	//mlx_loop_hook(mlx, mlx_resize_hook, NULL);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	return (EXIT_SUCCESS);
}

//compile with: cc window_open.c mlx/libmlx42.a -ldl -pthread -lm -L/Users/skorbai/.brew/Cellar/glfw/3.3.8/lib -lglfw -I mlx/MLX42.h
