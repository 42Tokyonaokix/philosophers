/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_gettime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:36:33 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/31 15:35:30 by natakaha         ###   ########.fr       */
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

pthread_mutex_t	*scythe(void)
{
	static pthread_mutex_t	*mutex;

	if (!mutex)
		mutex = setup_mutex(1);
	return (mutex);
}

int	death_inform(int i)
{
	static int	death = 0;

	pthread_mutex_lock(scythe());
	if (i == DEATH)
		death = DEATH;
	pthread_mutex_unlock(scythe());
	return (death);
}

int	waiting(int now, int time)
{
	while (timer() - now < time)
	{
		if (death_inform(0) == DEATH)
			return (DEATH);
		usleep(1);
	}
	return (now + time);
}
