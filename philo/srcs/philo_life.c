/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:00:14 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/09 19:30:31 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*life_manage(void *arg)
{
	t_philos	philo;
	int			flag;

	philo = *(t_philos *)arg;
	if (pthread_create(&philo.manager, NULL, is_living, &philo))
		return (NULL);
	if ((!(philo.num % 2) && !(philo.tag % 2))
		|| ((philo.num % 2) && (!(philo.tag % 2) || !(philo.num - philo.tag))))
		if (philos_think(philo) == FAILUER)
			return (NULL);
	while (true)
	{
		if (!(philo.tag % 2))
			flag = philos_eat(&philo, philo.left, philo.right);
		else
			flag = philos_eat(&philo, philo.right, philo.left);
		if (flag == FAILUER || flag == CLEAR
			|| philos_sleep(philo) == FAILUER
			|| philos_think(philo) == FAILUER)
			break ;
	}
	return (NULL);
}

int	philos_eat(t_philos *philo,
		pthread_mutex_t *first,
		pthread_mutex_t *next)
{
	int			now;

	if (philo->must == 0)
		return (CLEAR);
	if (have_forks(*philo, first, next) == FAILUER)
		return (FAILUER);
	philo->death_time = EATING;
	print_state(philo->tag, "is eating");
	philo->eat_n++;
	now = waiting(timer(), philo->eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
	if (now == DEATH)
		return (FAILUER);
	philo->death_time = timer() + philo->die;
	if (philo->must >= 0 && philo->eat_n >= philo->must)
	{
		philo->eat_n = CLEAR;
		return (CLEAR);
	}
	return (now);
}

int	philos_sleep(t_philos philo)
{
	int	now;

	now = timer();
	if (print_state(philo.tag, "is sleeping") == FAILUER)
		return (FAILUER);
	now = waiting(now, philo.slp);
	if (now != DEATH)
		return (now);
	print_state(philo.tag, "died");
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

int	philos_think(t_philos philo)
{
	int	now;
	int	thinking_time;

	now = timer();
	thinking_time = think_alg(philo);
	if (print_state(philo.tag, "is thinking") == FAILUER)
		return (FAILUER);
	now = waiting(now, thinking_time);
	if (now != DEATH)
		return (now);
	print_state(philo.tag, "died");
	return (FAILUER);
}
