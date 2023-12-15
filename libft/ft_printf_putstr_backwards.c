/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_backwards.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:34:54 by skorbai           #+#    #+#             */
/*   Updated: 2023/11/24 14:07:50 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printf_putstr_backwards(char *str, int i)
{
	int	len;
	int	error;

	len = 0;
	error = 0;
	while (i >= 0)
	{
		error = write(1, &str[i], 1);
		if (error < 0)
			return (-1);
		else
			len++;
		i--;
	}
	return (len);
}
