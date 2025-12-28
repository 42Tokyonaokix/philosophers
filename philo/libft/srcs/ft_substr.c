/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:56:26 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 03:04:29 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;

	count = 0;
	if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (count < len && s[count + start])
	{
		substr[count] = s[count + start];
		count++;
	}
	substr[count] = '\0';
	return (substr);
}

//int main (void)
//{
//	printf("%s\n", substr("0123456789", 0, 5));
//	printf("%s\n", substr("0123456789", 5, 5));
//	printf("%s\n", substr("0123456789", 7, 5));
//	printf("%s\n", substr("0123456789", 10, 5));
//	printf("%s\n", substr("0123456789", 25, 30));
//	printf("%s\n", substr("0123456789", 5, 25));
//}
