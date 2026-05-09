/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/09 10:47:04 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(const char *nptr)
{
	size_t			count;
	long long		number;

	count = 0;
	while (nptr[count] == ' ' || (9 <= nptr[count] && nptr[count] <= 13))
		count++;
	if (nptr[count] == '+')
		count++;
	number = 0;
	while ('0' <= nptr[count] && nptr[count] <= '9')
	{
		number = number * 10 + (nptr[count] - '0');
		if (number > INT_MAX)
			return (ERROR);
		count++;
	}
	if (nptr[count])
		return (ERROR);
	return ((int)number);
}
