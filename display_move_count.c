/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:57:26 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 16:33:34 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static void	display_header(t_data *assets)
{
	if (mlx_put_string(assets->window, "Number of moves: ", \
	(assets->window->width / 2), 0) == NULL)
	{
		perror("Error\nCannot display move count");
		return ;
	}
}*/

void	display_moves(t_data *assets, int move_count, char *text)
{
	char		*moves;
	char		*full_display;

	moves = ft_itoa(move_count);
	full_display = ft_strjoin(text, moves);
	mlx_delete_image(assets->window, assets->text);
	assets->text = mlx_put_string(assets->window, full_display, 0, 0);
	free(full_display);
}
