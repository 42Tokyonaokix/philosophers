/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:00:14 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/31 15:00:57 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	philos_eat(t_philos *philo,
				pthread_mutex_t *first, pthread_mutex_t *next);
static int	philos_sleep(t_philos philo);

void	*life_manage(void *arg)
{
	t_philos	philo;
	int			flag;

	philo = *(t_philos *)arg;
	if (pthread_create(&philo.manager, NULL, is_living, &philo))
		return (NULL);
	if (first_think(philo) == FAILUER)
		return ((void)pthread_join(philo.manager, NULL), NULL);
	while (true)
	{
		if (!(philo.tag % 2))
			flag = philos_eat(&philo, philo.left, philo.right);
		else
			flag = philos_eat(&philo, philo.right, philo.left);
		if (flag == CLEAR)
			print_state(CLOSE, NULL);
		if (flag == FAILUER || flag == CLEAR
			|| philos_sleep(philo) == FAILUER
			|| philos_think(philo) == FAILUER)
			break ;
	}
	return ((void)pthread_join(philo.manager, NULL), NULL);
}

static int	philos_eat(t_philos *philo,
		pthread_mutex_t *first,
		pthread_mutex_t *next)
{
	int			now;

	if (philo->must == 0)
		return (CLEAR);
	if (have_forks(*philo, first, next) == FAILUER)
		return (FAILUER);
	philo->death_time = timer() + philo->die;
	print_state(philo->tag, "is eating");
	philo->eat_n++;
	now = waiting(timer(), philo->eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
	if (now == DEATH)
		return (FAILUER);
	if (philo->must >= 0 && philo->eat_n >= philo->must)
	{
		philo->eat_n = CLEAR;
		return (CLEAR);
	}
	return (now);
}

static int	philos_sleep(t_philos philo)
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
