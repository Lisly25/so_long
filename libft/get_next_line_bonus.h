/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:42:51 by skorbai           #+#    #+#             */
/*   Updated: 2023/12/05 12:57:32 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

char	*get_next_line(int fd);

char	*gnl_strdup(const char *s, int bytes, int is_leftover);

char	*newline_strdup(char *str);

char	*ft_strchr(const char *s, int c);

char	*gnl_strjoin(char const *pref, char const *suff, ssize_t bytes);

char	*malloc_fail_cleanup(char **leftover);

#endif