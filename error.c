/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:00:56 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/02 13:33:51 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_error(void)
{
	ft_printf("\nError");
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
