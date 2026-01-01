/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gettime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:36:33 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/01 23:05:18 by natakaha         ###   ########.fr       */
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

int	waiting(int death, int now, int time)
{
	while (timer() - now < time)
	{
		if (death >= 0 && timer() >= death)
			return (DEATH);
	}
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