/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:36:39 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/21 14:47:29 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*make_buff_large(char *buff);

char	*ft_itoa_hexb(unsigned int n)
{
	size_t						n_digit;
	unsigned int				temp;
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
	itoa = digit_allocate_buff(n, itoa, n_digit, make_buff_large(buff));
	return (itoa);
}

static char	*make_buff_large(char *buff)
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
	buff[10] = 'A';
	buff[11] = 'B';
	buff[12] = 'C';
	buff[13] = 'D';
	buff[14] = 'E';
	buff[15] = 'F';
	return (buff);
}
