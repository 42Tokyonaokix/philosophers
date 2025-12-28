/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 09:26:58 by natakaha          #+#    #+#             */
/*   Updated: 2025/09/09 12:28:40 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	int					dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

//int main(void)
//{
//	char dest1[30] = "ABCDE";
//	char dest2[30] = "ABCDE";
//	char src[30] = "XYZ";
//	unsigned int n = 2;

//	printf("%s\n",ft_strncat(dest1, src, n));
//	printf("%s",strncat(dest2,src,n));
//}
