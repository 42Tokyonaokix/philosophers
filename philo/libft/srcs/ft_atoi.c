/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:27:18 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 03:03:21 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
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
