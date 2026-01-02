/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:00:14 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/02 07:47:14 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*alg_manage(void *arg)
{
	t_philos	philo;

	philo = *(t_philos *)arg;
	while (timer() < (philo.tag % 2))
		;
	while (true)
	{
		if (!(philo.tag % 2))
			philos_eat(&philo, philo.left, philo.right);
		else
			philos_eat(&philo, philo.right, philo.left);

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
	now = waiting(now, philo->eat);
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(next);
	if (philo->must >= 0 && philo->eat_n >= philo->must)
		return (CLEAR);
	return (now);
}

int	philos_sleep(t_philos philo)
{
	int	now;

	now = timer();
	if (print_state(now, philo.tag, "is sleeping") == FAILUER)
		return (FAILUER);
	now = waiting(now, philo.slp);
	return (now);
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
	return (now);
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
	if (create_and_join(i, philo, alg_manage) == FAILUER)
		return (1);
	return (0);
}
