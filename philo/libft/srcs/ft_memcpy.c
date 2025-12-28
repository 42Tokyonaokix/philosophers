/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:44:36 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:45:21 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			count;

	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	count = 0;
	while (psrc && pdest && count < n)
	{
		pdest[count] = psrc[count];
		count++;
	}
	return (pdest);
}
