/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:38:43 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/16 11:11:01 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map)
{
	if (check_char_num(map) == 0)
		return (0);
	if (check_chars(map) == 1)
		return (0);
	if (is_rectangle(map) == 1)
		return (0);
	if (is_walled(map) == 1)
	{
		perror("Error\nMap must be surrounded by walls");
		return (0);
	}
	return (1);
}
