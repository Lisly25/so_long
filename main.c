/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:35:59 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 11:01:14 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
		ft_error("Error\nProgram must have exactly 1 argument, the map\n");
	if (validate_map(argv[1]) == 1)
		return (EXIT_FAILURE);
	data = init_window(argv[1]);
	draw_map(data);
	mlx_key_hook(data->window, ft_key_hook, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	free(data);
	return (EXIT_SUCCESS);
}
