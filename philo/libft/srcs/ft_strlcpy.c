/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:53:13 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/31 16:25:49 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	if (dstsize <= 0)
		return (ft_strlen(src));
	count = 0;
	while (src[count] && count < dstsize -1)
	{
		dst[count] = src [count];
		count++;
	}
	dst[count] = '\0';
	return (ft_strlen(src));
}

//int main()
//{
//	char src[] = "coucou";
//	char dest[10]; memset(dest, 'A', 10);
//	printf("%ld\n",ft_strlcpy(dest, src, 1));
//	printf("%c\n",dest[0]);
//	printf("%c\n",dest[1]);
//}
