/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gettime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:36:33 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/09 19:29:05 by natakaha         ###   ########.fr       */
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

int	death_inform(int i)
{
	static int	death = 0;

	if (i == DEATH)
		death = DEATH;
	return (death);
}

void	*is_living(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (true)
	{
		if (death_inform(0) == DEATH)
			return (NULL);
		if (0 < philo->death_time
			&& philo->death_time < timer()
			&& 0 < philo->death_time)
		{
			print_state(philo->tag, "died");
			death_inform(DEATH);
		}
		if (philo->must == CLEAR)
			return (NULL);
		if (philo->death_time == EATING)
			continue ;
	}
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
