/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:35:37 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/20 11:07:41 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "vector.h"

t_vector	*read_map(void);

int			count_chars(char **map, char c);

int			check_chars(char **map);

int			check_char_num(char **map);

int			check_map(t_vector *map);

int			is_rectangle(char **map);

int			is_walled(char **map);

int			check_path(t_vector *map);

#endif