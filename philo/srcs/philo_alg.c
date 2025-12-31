/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:00:14 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/31 18:33:18 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*alg_manage(void *arg)
{
	t_philos	philo;

	philo = *(t_philos *)arg;
	while (timer() < (philo.tag % 2))
		;
	if (!(philo.tag % 2))
		philos_eat(philo, philo.left, philo.right);
	else
		philos_eat(philo, philo.right, philo.left);
	return (NULL);
}

int	philos_eat(t_philos philo,
		pthread_mutex_t *first,
		pthread_mutex_t *next)
{
	static int	i;
	int			now;

	if (have_a_fork(philo, first, next) == FAILUER)
		return (FAILUER);
	now = timer();
	if (print_state(now, philo.tag, "is eating") == FAILUER)
		return (FAILUER);
	i++;
	now = waiting(now, philo.eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
	if (i >= philo.must)
		return (SUCCESS);
	return (0);
}

int	philos_sleep_think(t_philos philo)
{
	int	now;
	int	thinking_time;

	now = timer();
	if (print_state(now, philo.tag, "is sleeping") == FAILUER)
		return (FAILUER);
	now = waiting(now, philo.slp);
	thinking_time = philo.eat - philo.slp;
	if (thinking_time < 0)
		return (SUCCESS);
	if (print_state(now, philo.tag, "is thinking") == FAILUER)
		return (FAILUER);
	now = waiting(now, thinking_time);
	return (SUCCESS);
}
