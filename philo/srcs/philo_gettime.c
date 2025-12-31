/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gettime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:36:33 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/31 16:49:52 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ms(void)
{
	struct timeval	tv;
	int				ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

int	timer(void)
{
	static int	start;
	int			t;

	t = ms();
	if (!start)
		start = t;
	return (t - start);
}

int	waiting(int now, int time)
{
	while (timer() - now < time)
		;
	return (now + time);
}

//int	main(void)
//{
//	ft_printf("%d\n", timer());
//	usleep(1000);
//	ft_printf("%d\n", timer());
//	usleep(1000);
//	ft_printf("%d\n", timer());
//	usleep(1000);
//	ft_printf("%d\n", timer());
//	usleep(1000);
//}