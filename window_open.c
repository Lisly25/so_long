/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:01:29 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/21 11:54:56 by skorbai          ###   ########.fr       */
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

	cat_sitting = mlx_load_png("../textures/cat/Cat_sitting.png");
	if (!cat_sitting)
		error();
	house = mlx_load_png("../textures/house/house.png");
	if (!house)
		error();
	data->player = mlx_texture_to_image(data->window, cat_sitting);
	if (!data->player)
        error();
	data->exit = mlx_texture_to_image(data->window, house);
	if (!data->exit)
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
		image->instances[0].y -= 20;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 20;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 20;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 20;
}

int32_t	main(void)
{
	t_data	*data;

	data = init_window();
	if (mlx_resize_image(data->player, 500, 500) != true)
		error();
	ft_printf("Break\n");
	if (mlx_image_to_window(data->window, data->player, 0, 0) < 0)
        error();
	ft_printf("Break2\n");
	if (mlx_resize_image(data->exit, 500, 500) != true)
		error();
	if (mlx_image_to_window(data->window, data->exit, 600, 600) < 0)
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
