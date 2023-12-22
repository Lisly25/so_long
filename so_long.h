/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:35:37 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/22 12:58:24 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "vector.h"
# include "mlx/MLX42.h"
# include "libft/libft.h"

# define WIDTH 600
# define HEIGHT 600

typedef struct s_data {
	mlx_t		*window;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*tree;
	mlx_image_t	*background;
	mlx_image_t	*bird;
	t_vector	*map;
}	t_data;

int			validate_map(void);

t_vector	*read_map(void);

int			count_chars(char **map, char c);

int			check_chars(char **map);

int			check_char_num(char **map);

int			is_rectangle(char **map);

int			is_walled(char **map);

int			check_path(t_vector *map);

t_data		*init_window(void);

void		draw_map(t_vector *map, t_data *assets);

void		ft_key_hook(mlx_key_data_t key_data, void *param);

void		move_check(t_data *assets, int mode);

int			check_for_win(t_data *assets);

void		free_map(t_vector *map);

void		exit_game(t_data *assets);

#endif