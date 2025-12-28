/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:34:20 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/23 04:06:40 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strchr_len(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strdup(const char *str);
char	*exec_before_n(char	*str);
char	*proceed_after_n(char	*str);
char	*get_next_line(int fd);

#endif
