/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:01:29 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/20 16:00:42 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/MLX42.h"

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

void ft_hook(mlx_t *mlx, mlx_image_t *image)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*cat_sitting;
	mlx_image_t		*cat_image;
	mlx_texture_t	*house;
	mlx_image_t		*exit_image;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Hungry Cat", true);
	if (!mlx)
		ft_error();
	cat_sitting = mlx_load_png("../textures/cat/Cat_sitting.png");
	if (!cat_sitting)
		error();
	house = mlx_load_png("../textures/house/house.png");
	if (!house)
		error();
	cat_image = mlx_texture_to_image(mlx, cat_sitting);
	if (!cat_image)
        error();
	exit_image = mlx_texture_to_image(mlx, house);
	if (!exit_image)
        error();
	if (mlx_resize_image(cat_image, 500, 500) != true)
		error();
	if (mlx_image_to_window(mlx, cat_image, 0, 0) < 0)
        error();
	if (mlx_resize_image(exit_image, 500, 500) != true)
		error();
	if (mlx_image_to_window(mlx, exit_image, 600, 600) < 0)
        error();
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

//compile with: cc window_open.c mlx/libmlx42.a -ldl -pthread -lm -L/Users/skorbai/.brew/Cellar/glfw/3.3.8/lib -lglfw -I mlx/MLX42.h
