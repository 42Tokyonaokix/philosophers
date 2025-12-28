/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_alpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:12:16 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:19:03 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_atoi_alpha1(const char *nptr)
{
	size_t	count;
	int		number;
	int		neg;

	count = 0;
	neg = 1;
	while (nptr[count] == ' ' || (9 <= nptr[count] && nptr[count] <= 13))
		count++;
	if (nptr[count] == '+')
		count++;
	else if (nptr[count] == '-')
	{
		neg = -1;
		count++;
	}
	number = 0;
	while ('0' <= nptr[count] && nptr[count] <= '9')
	{
		number = number * 10 + (nptr[count] - '0');
		count++;
	}
	return (number * neg);
}

int	ft_atoi_alpha(const char *nptr)
{
	int	atoi;

	atoi = ft_atoi_alpha1(nptr);
	if (atoi < 0)
		return (-1);
	return (atoi);
}

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
