/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:44:56 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 23:25:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*digit_allocate_signed(int n, char *itoa, size_t index);

char	*ft_itoa(int n)
{
	size_t				n_digit;
	long long int		temp;
	char				*itoa;

	temp = n;
	n_digit = 1;
	if (temp < 0)
	{
		temp = -temp;
		n_digit++;
	}
	while (temp >= 10)
	{
		n_digit++;
		temp = temp / 10;
	}
	itoa = (char *)malloc(sizeof(char) * (n_digit + 1));
	if (itoa == NULL)
		return (NULL);
	itoa = digit_allocate_signed(n, itoa, n_digit);
	return (itoa);
}

static char	*digit_allocate_signed(int n, char *itoa, size_t index)
{
	if (n == 0)
		return (ft_strcpy(itoa, "0"));
	if (n == INT_MIN)
		return (ft_strcpy(itoa, "-2147483648"));
	if (n < 0)
	{
		itoa[0] = '-';
		n = -n;
	}
	itoa[index] = '\0';
	while (n > 0)
	{
		index--;
		itoa[index] = n % 10 + '0';
		n = n / 10;
	}
	return (itoa);
}
