/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:00:14 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/01 23:03:11 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*alg_manage(void *arg)
{
	t_philos	philo;
	int			death;

	philo = *(t_philos *)arg;
	while (timer() < (philo.tag % 2))
		;
	while (true)
	{
		if (!(philo.tag % 2))
			death = philos_eat(&philo, philo.left, philo.right);
		else
			death = philos_eat(&philo, philo.right, philo.left);
		if (death == CLEAR || death == FAILUER)
			return (NULL);
		death = philos_sleep_think(philo, death);
		if (death == FAILUER)
			print_state(timer(), philo.tag, "some serious problem occured");
		else if (death == DEATH)
			print_state(timer(), philo.tag, "died");
		if (death == FAILUER || death == DEATH)
			return (NULL);
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
	if (have_a_fork(*philo, first, next) == FAILUER)
		return (FAILUER);
	now = timer();
	if (print_state(now, philo->tag, "is eating") == FAILUER)
		return (FAILUER);
	philo->eat_n++;
	now = waiting(EATING, now, philo->eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
	if (philo->must >= 0 && philo->eat_n >= philo->must)
		return (CLEAR);
	return (now + philo->die);
}

int	philos_sleep_think(t_philos philo, int death)
{
	int	now;
	int	thinking_time;

	now = timer();
	if (print_state(now, philo.tag, "is sleeping") == FAILUER)
		return (FAILUER);
	now = waiting(death, now, philo.slp);
	if (now == DEATH)
		return (DEATH);
	thinking_time = philo.eat - philo.slp;
	if (thinking_time < 0)
		return (SUCCESS);
	if (print_state(now, philo.tag, "is thinking") == FAILUER)
		return (FAILUER);
	now = waiting(death, now, thinking_time);
	if (now == DEATH)
		return (DEATH);
	return (SUCCESS);
}
