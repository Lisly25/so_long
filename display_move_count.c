/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:57:26 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/02 10:11:36 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_data *assets, int move_count, char *text)
{
	char		*moves;
	char		*full_display;

	moves = ft_itoa(move_count);
	full_display = ft_strjoin(text, moves);
	mlx_delete_image(assets->window, assets->text);
	assets->text = mlx_put_string(assets->window, full_display, 0, 0);
	free(full_display);
	free (moves);
	return ;
}
