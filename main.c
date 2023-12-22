/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:35:59 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 12:59:16 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(void)
{
	t_data		*data;

	if (validate_map() == 1)
		return (1);
	data = init_window();
	draw_map(data->map, data);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_key_hook(data->window, ft_key_hook, data);
	//mlx_loop_hook(mlx, mlx_resize_hook, NULL);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	return (EXIT_SUCCESS);
}
