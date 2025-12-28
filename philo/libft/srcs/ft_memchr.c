/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:43:25 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:43:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned const char	*p;
	size_t				count;

	p = (unsigned const char *)b;
	count = 0;
	while (count < len)
	{
		if (p[count] == (unsigned char)c)
			return ((void *)&p[count]);
		count++;
	}
	return (NULL);
}
