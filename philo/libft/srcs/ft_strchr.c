/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:49:11 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/16 02:49:26 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	while (s[count - 1] || count == 0)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count++;
	}
	return (NULL);
}
