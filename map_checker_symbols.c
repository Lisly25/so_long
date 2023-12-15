/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_symbols.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:16:14 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/15 15:50:59 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_chars_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'P' || \
		map[i] == 'E' || map [i] == 'C' || map[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_chars(char **map)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (map[i])
	{
		result = check_chars_line(map[i]);
		if (result == 1)
		{
			perror("Invalid symbol in map");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	count_chars_line(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}

static int	count_chars(char **map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		count = count + count_chars_line(map[i], c);
		i++;
	}
	return (count);
}

int	check_char_num(char **map)
{
	if (count_chars(map, 'P') != 1)
	{
		perror("Map error: number of starting positions must be 1");
		return (0);
	}
	else if (count_chars(map, 'E') != 1)
	{
		perror("Map error: number of exits must be 1");
		return (0);
	}
	else if (count_chars(map, 'C') < 1)
	{
		perror("Map error: no collectibles");
		return (0);
	}
	return (1);
}
