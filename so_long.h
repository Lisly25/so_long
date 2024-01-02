/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:35:37 by skorbai           #+#    #+#             */
/*   Updated: 2024/01/02 16:18:10 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <stdarg.h>
# include "vector.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define SCALE 150
# define PLAYER_PATH "./textures/Cat_sitting.png"
# define COLLECTIBLE_PATH "./textures/bird.png"
# define TREE_PATH "./textures/tree.png"
# define GROUND_PATH "./textures/backdrop.png"
# define EXIT_PATH "./textures/house.png"

typedef struct s_data {
	mlx_t		*window;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*tree;
	mlx_image_t	*background;
	mlx_image_t	*bird;
	t_vector	*map;
	mlx_image_t	*text;
}	t_data;

int			validate_map(char *map_path);

t_vector	*read_map(char *map_path);

int			count_chars(char **map, char c);

int			check_chars(char **map);

int			check_char_num(char **map);

int			is_rectangle(char **map);

int			is_walled(char **map);

int			check_path(t_vector *map);

t_data		*init_window(char *map_path);

void		draw_map(t_vector *map, t_data *assets);

void		ft_key_hook(mlx_key_data_t key_data, void *param);

void		move_check(t_data *assets, int mode);

int			check_for_win(t_data *assets);

void		free_map(t_vector *map);

void		exit_game(t_data *assets);

void		display_moves(int move_count, char *text);

void		delete_textures(mlx_texture_t *texture, ...);

void		ft_mlx_error(void);

void		ft_error(const char *str);

#endif