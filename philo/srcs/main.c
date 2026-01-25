/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/25 06:22:34 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	philos_join(t_philos *philo, int i);


int	main(int argc, char **argv)
{
	int				i;
	t_philos		*philo;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("invalid arg number", 2), 1);
	i = ft_atoi(argv[1]);
	if (i < 0)
		return (ft_putendl_fd("invalid philos number", 2), 1);
	forks = setup_mutex(i);
	if (!forks)
		return (ft_putendl_fd("failed", 2), 1);
	philo = set_philo_fork(i, argv, forks);
	if (!philo)
		return (ft_putendl_fd("failed", 2), 1);
	if (create_and_join(i, philo, forks) == FAILUER)
		return (1);
	return (0);
}

int	create_and_join(int n, t_philos *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	microphone();
	timer();
	while (i < n)
	{
		if (pthread_create(&philo[i].thread, NULL, life_manage, &philo[i]))
			break ;
		i++;
	}
	philos_join(philo, i);
	while (n--)
		pthread_mutex_destroy(&forks[n]);
	pthread_mutex_destroy(microphone());
	free(philo);
	free(forks);
	free(microphone());
	return (SUCCESS);
}

static void	philos_join(t_philos *philo, int i)
{
	while (i--)
		pthread_join(philo[i].thread, NULL);
	return ;
}

