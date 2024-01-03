/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_count_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:57:26 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/03 11:27:04 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves_bonus(t_data *assets, int move_count, char *text)
{
	char		*moves;
	char		*full_display;

	moves = ft_itoa(move_count);
	full_display = ft_strjoin(text, moves);
	mlx_delete_image(assets->window, assets->text);
	assets->text = mlx_put_string(assets->window, full_display, 0, 0);
	if (!assets->text)
		ft_mlx_error(assets);
	free(full_display);
	free (moves);
	return ;
}

void	display_initial_moves_bonus(t_data *assets)
{
	assets->text = mlx_put_string(assets->window, "Number of moves: 0", 0, 0);
	if (!assets->text)
		ft_mlx_error(assets);
	return ;
}
