/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flag_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:51:59 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 09:18:56 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	display_c_minus(char *arg, t_flag flag);
static int	display_c_no_minus(char *arg, t_flag flag);

int	display_c(char *arg, t_flag flag)
{
	size_t	count;
	size_t	size;

	size = 1;
	if (flag.width > size)
		size = flag.width;
	count = 0;
	if (flag.minus)
	{
		count = display_c_minus(arg, flag);
	}
	if (!flag.minus)
	{
		count = display_c_no_minus(arg, flag);
	}
	return (count);
}

static int	display_c_minus(char *arg, t_flag flag)
{
	size_t	count;

	count = 0;
	if (ft_putchar_fd(arg[0], 1) < 0)
		return (-1);
	count++;
	while (count < flag.width)
	{
		if (ft_putchar_fd(' ', 1) < 0)
			return (-1);
		count++;
	}
	return (count);
}

static int	display_c_no_minus(char *arg, t_flag flag)
{
	size_t	count;

	count = 0;
	while (count + 1 < flag.width)
	{
		if (ft_putchar_fd(' ', 1) < 0)
			return (-1);
		count++;
	}
	if (ft_putchar_fd(arg[0], 1) < 0)
		return (-1);
	count++;
	return (count);
}

static char	*treat_flag_c(char c, t_flag flag)
{
	size_t	size;
	char	*dest;

	size = flag.width;
	if (size < 1)
		size = 1;
	dest = (char *)malloc(sizeof(char) * 2);
	dest[0] = c;
	dest[1] = '\0';
	if (dest == NULL)
		return (NULL);
	return (dest);
}

char	*return_c(va_list args, t_flag flag)
{
	char	c;
	char	*str;

	c = va_arg(args, int);
	str = treat_flag_c(c, flag);
	(void)flag;
	return (str);
}
