/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:39:28 by skorbai           #+#    #+#             */
/*   Updated: 2023/11/24 14:07:34 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);

int	printf_putchar(char c);

int	printf_arg_putstr(char *str);

int	printf_void(uintptr_t adress);

int	printf_putnbr(int num);

int	printf_hex(unsigned int num, int hex_case);

int	printf_putstr_backwards(char *str, int i);

int	printf_uint(unsigned int num);

#endif