/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/15 17:18:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	count;

	count = 0;
	while ((s1[count] || s2[count]) && count < len)
	{
		if (s1[count] != s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return (0);
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_atoi(const char *nptr)
{
	size_t	count;
	int		number;
	int		neg;

	count = 0;
	neg = 1;
	while (nptr[count] == ' ' || (9 <= nptr[count] && nptr[count] <= 13))
		count++;
	if (nptr[count] == '+')
		count++;
	else if (nptr[count] == '-')
	{
		neg = -1;
		count++;
	}
	number = 0;
	while ('0' <= nptr[count] && nptr[count] <= '9')
	{
		number = number * 10 + (nptr[count] - '0');
		count++;
	}
	return (number * neg);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	lnb;
	void	*ptr;

	lnb = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (SIZE_MAX / nmemb < size || (int)nmemb < 0 || (int)size < 0)
		return (NULL);
	ptr = malloc(lnb);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, lnb);
	return (ptr);
}
