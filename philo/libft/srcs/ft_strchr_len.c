/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:00:20 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/09 20:57:48 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strchr_len(const char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (-1);
	if (c == '\0')
	{
		while (s[count])
			count++;
		return (count);
	}
	while (s[count])
	{
		if (s[count] == (char)c)
			return (count);
		count++;
	}
	return (-1);
}
