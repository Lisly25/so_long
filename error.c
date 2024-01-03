/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:56 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 10:53:37 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_error(t_data *data)
{
	ft_printf("\nError");
	puts(mlx_strerror(mlx_errno));
	free_map(data->map);
	mlx_close_window(data->window);
	mlx_terminate(data->window);
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_error_message(const char *str)
{
	perror(str);
	return (1);
}
