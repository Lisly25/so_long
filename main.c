/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:35:59 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/02 12:02:01 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(void)
{
	t_data		*data;

	if (validate_map() == 1)
		return (EXIT_FAILURE);
	data = init_window();
	draw_map(data->map, data);
	mlx_key_hook(data->window, ft_key_hook, data);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	free(data);
	return (EXIT_SUCCESS);
}
