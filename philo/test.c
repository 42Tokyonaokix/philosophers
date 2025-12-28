/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-23 09:33:04 by natakaha          #+#    #+#             */
/*   Updated: 2025-12-23 09:33:04 by natakaha         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*hello_world(void *arg)
{
	int	i;

	i = *(int *)arg;
	ft_putstr_fd("I am", 1);
	ft_putnbr_fd(i, 1);
	ft_putendl_fd("th philosopher", 1);
	return (NULL);
}

//int	main(void)
//{
//	int			i;
//	pthread_t	*lst;
	
//	i = 0;
//	lst = (pthread_t *)ft_calloc(7, sizeof(pthread_t));
//	if (!lst)
//		return (1);
//	while (i < 7)
//	{
//		if (pthread_create(&lst[i], NULL, hello_world, &i))
//			return (1);
//		pthread_join(lst[i], NULL);
//		i++;
//	}	
//}

#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%ld:%ld",tv.tv_sec, tv.tv_usec);
}