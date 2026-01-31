/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/31 15:01:27 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	have_forks(t_philos philo,
	pthread_mutex_t *first,
	pthread_mutex_t *next)
{
	if (!pthread_mutex_lock(first))
	{
		print_state(philo.tag, "has taken a fork");
		pthread_mutex_lock(next);
		print_state(philo.tag, "has taken a fork");
		return (SUCCESS);
	}
	return (FAILUER);
}

int	think_alg(t_philos philo)
{
	int	time;
	int	group;

	group = philo.num / 2;
	if (!(philo.num % 2))
		time = philo.eat - philo.slp;
	else
	{
		if (!philo.eat_n && philo.tag == philo.num)
			time = philo.eat * 2 - philo.slp;
		else if (philo.eat_n && philo.group % group == philo.eat_n % group)
			time = philo.eat * 2 - philo.slp;
		else
			time = philo.eat - philo.slp;
	}
	if (time < 0)
		time = 0;
	return (time);
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
	}
}

int	first_think(t_philos philo)
{
	int	flag;

	flag = false;
	if (!(philo.num % 2) && !(philo.tag % 2))
		flag = true;
	else if ((philo.num % 2) && (!(philo.tag % 2) || !(philo.num - philo.tag)))
		flag = true;
	if (flag == false)
		return (SUCCESS);
	return (philos_think(philo));
}
