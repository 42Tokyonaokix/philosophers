/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:00:14 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/06 23:11:56 by natakaha         ###   ########.fr       */
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
	while (timer() < (philo.tag % 2))
		;
	while (true)
	{
		if (!(philo.tag % 2))
			flag = philos_eat(&philo, philo.left, philo.right);
		else
			flag = philos_eat(&philo, philo.right, philo.left);
		if (flag == FAILUER)
			break ;
		else if (flag == CLEAR)
			return (NULL);
		if (philos_sleep(philo) == FAILUER
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
	if (have_a_fork(*philo, first, next) == FAILUER)
		return (FAILUER);
	philo->death_time = EATING;
	now = timer();
	if (print_state(now, philo->tag, "is eating") == FAILUER)
		return (FAILUER);
	philo->eat_n++;
	now = waiting(now, philo->eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
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
	if (print_state(now, philo.tag, "is sleeping") == FAILUER)
		return (FAILUER);
	now = waiting(now, philo.slp);
	if (now != DEATH)
		return (now);
	print_state(timer(), philo.tag, "died");
	return (FAILUER);
}

int	philos_think(t_philos philo)
{
	int	now;
	int	thinking_time;

	now = timer();
	thinking_time = 0;
	if (print_state(now, philo.tag, "is thinking") == FAILUER)
		return (FAILUER);
	now = waiting(now, thinking_time);
	if (now != DEATH)
		return (now);
	print_state(timer(), philo.tag, "died");
	return (FAILUER);
}

int	main(int argc, char **argv)
{
	int			i;
	t_philos	*philo;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("invalid arg number", 2), 1);
	i = ft_atoi(argv[1]);
	philo = set_philo_fork(i, argv);
	if (!philo)
		return (1);
	if (create_and_join(i, philo, life_manage) == FAILUER)
		return (1);
	return (0);
}
