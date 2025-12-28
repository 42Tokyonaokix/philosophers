/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:40:41 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 23:20:39 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*digit_allocate_buff(long long unsigned int n,
				char *itoa, size_t index, char *buff);
static char	*make_buff_small(char *buff);

char	*ft_itoa_hexs(long long unsigned int n)
{
	size_t						n_digit;
	long long unsigned int		temp;
	char						*itoa;
	char						buff[16];

	temp = n;
	n_digit = 1;
	while (temp >= 16)
	{
		n_digit++;
		temp = temp / 16;
	}
	itoa = (char *)malloc(sizeof(char) * (n_digit + 1));
	if (itoa == NULL)
		return (NULL);
	itoa = digit_allocate_buff(n, itoa, n_digit, make_buff_small(buff));
	return (itoa);
}

static char	*make_buff_small(char *buff)
{
	buff[0] = '0';
	buff[1] = '1';
	buff[2] = '2';
	buff[3] = '3';
	buff[4] = '4';
	buff[5] = '5';
	buff[6] = '6';
	buff[7] = '7';
	buff[8] = '8';
	buff[9] = '9';
	buff[10] = 'a';
	buff[11] = 'b';
	buff[12] = 'c';
	buff[13] = 'd';
	buff[14] = 'e';
	buff[15] = 'f';
	return (buff);
}

char	*digit_allocate_buff(long long unsigned int n,
			char *itoa, size_t index, char *buff)
{
	if (n == 0)
		return (ft_strcpy(itoa, "0"));
	itoa[index] = '\0';
	while (n > 0)
	{
		index--;
		itoa[index] = buff[n % 16];
		n = n / 16;
	}
	return (itoa);
}
