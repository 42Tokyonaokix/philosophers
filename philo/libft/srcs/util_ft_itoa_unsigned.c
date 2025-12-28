/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:45:50 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:19:43 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	size_t				n_digit;
	long long int		temp;
	char				*itoa;

	temp = n;
	n_digit = 1;
	while (temp >= 10)
	{
		n_digit++;
		temp = temp / 10;
	}
	itoa = (char *)malloc(sizeof(char) * (n_digit + 1));
	if (itoa == NULL)
		return (NULL);
	itoa = digit_allocate_unsigned(n, itoa, n_digit);
	return (itoa);
}

char	*digit_allocate_unsigned(unsigned int n, char *itoa, size_t index)
{
	if (n == 0)
		return (ft_strcpy(itoa, "0"));
	itoa[index] = '\0';
	while (n > 0)
	{
		index--;
		itoa[index] = n % 10 + '0';
		n = n / 10;
	}
	return (itoa);
}

//static char	*ft_strcpy(char *dest, const char *src)
//{
//	size_t	index;

//	index = 0;
//	while (src[index])
//	{
//		dest[index] = src[index];
//		index++;
//	}
//	dest[index] = '\0';
//	return (dest);
//}