/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:12:37 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/25 12:36:43 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flag
{
	bool	minus;
	bool	plus;
	bool	space;
	bool	zero;
	bool	sharp;
	bool	prezero;
	size_t	width;
	size_t	precision;
	char	format;
}	t_flag;

// treat first argument

bool	detect_flag(char c);
bool	detect_width(char c);
bool	detect_format(char c);

size_t	count_flag(const char *str);
size_t	count_width(const char *str);
size_t	count_precision(const char *str);
size_t	percent_len(const char *percent);
int		count_percent(const char *format);

char	**split_percent(const char *format);

// treat flags

t_flag	*allocate_flags(char **formlist, t_flag *flaglist);

t_flag	char_to_flag(char c, t_flag flag);
t_flag	str_to_flag(const char *str, t_flag flag);
t_flag	str_to_width(const char *str, t_flag flag);
t_flag	str_to_precision(const char *str, t_flag flag);
t_flag	str_format(const char *str, t_flag flag);

t_flag	*management_flaglist(const char *format, char **formlist);

// treat second after argument

char	*return_c(va_list args, t_flag flaglist);

char	*return_s(va_list args, t_flag flaglist);

char	*return_di(va_list args, t_flag flaglist);

char	*treat_flag_di_h(char *itoa, t_flag flag, char *dest, size_t size);

char	*treat_flag_di_n(char *itoa, t_flag flag, char *dest, size_t size);

char	*return_u(va_list args, t_flag flaglist);
char	*return_x(va_list args, t_flag flaglist);
char	*return_large_x(va_list args, t_flag flaglist);
char	*return_p(va_list args, t_flag flaglist);

char	*treat_flag_u(char	*itoa, t_flag flag);

char	*treat_flag_x(char	*itoa, t_flag flag);

char	*treat_flag_lx(char	*itoa, t_flag flag);

char	*treat_flag_p(char	*itoa, t_flag flag);

void	free_formlist(char **formlist, size_t count);
void	free_arglist(char **arglist, size_t count);
// free flaglist is not because simply free.

char	**management_arglist(va_list args,
			const char *format, t_flag *flaglist);
int		display_c(char *arg, t_flag flag);

int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
size_t	minimum(size_t d1, size_t d2);
char	*ft_strcpy(char *dest, const char *src);
size_t	return_maximum(size_t s1, size_t s2, size_t s3);

char	*ft_itoa_hexb(unsigned int n);
char	*ft_itoa_hexs(long long unsigned int n);
char	*digit_allocate_buff(long long unsigned int n,
			char *itoa, size_t index, char *buff);

char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
char	*digit_allocate_unsigned(unsigned int n, char *itoa, size_t index);

int		ft_putchar_int(char c, int fd);
int		ft_putstr_int(char *s, int fd);
int		ft_atoi_alpha(const char *nptr);

#endif