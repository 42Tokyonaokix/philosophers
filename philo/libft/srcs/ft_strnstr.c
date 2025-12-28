/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:54:39 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:55:16 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_strs2cmp(const char *s1, const char *s2)
{
	size_t	count;

	if (ft_strlen(s2) == 0)
		return (0);
	count = 0;
	while (s2[count])
	{
		if (s1[count] != s2[count])
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strnstr(const char *big,	const char *little, size_t len)
{
	size_t	count;
	size_t	len_little;

	count = 0;
	len_little = ft_strlen(little);
	if (len_little == 0)
		return ((char *)big);
	while (*big && count + len_little - 1 < len)
	{
		if (ft_strs2cmp(big, little) == 0)
			return ((char *)big);
		big++;
		count++;
	}
	return (NULL);
}
