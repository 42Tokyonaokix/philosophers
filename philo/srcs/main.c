/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/31 15:38:29 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	philos_join(t_philos *philo, int i);
static void	mutex_free(pthread_mutex_t *mutex, int n);

int	main(int argc, char **av)
{
	int				i;
	t_philos		*philo;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd("invalid arg number", 2), 1);
	if (ft_atoi(av[1]) == -1 || ft_atoi(av[2]) == -1 || ft_atoi(av[3]) == -1
		|| ft_atoi(av[4]) == -1 || (argc == 6 && ft_atoi(av[5]) == -1))
		return (ft_putendl_fd("invalid argument", 2), 1);
	i = ft_atoi(av[1]);
	forks = setup_mutex(i);
	if (!forks)
		return (ft_putendl_fd("failed", 2), 1);
	philo = set_philo_fork(i, av, forks);
	if (!philo)
		return (ft_putendl_fd("failed", 2), 1);
	if (create_and_join(i, philo, forks) == FAILUER)
		return (1);
	return (0);
}

int	create_and_join(int n, t_philos *philo, pthread_mutex_t *forks)
{
	int	i;
	int	flag;

	i = 0;
	flag = SUCCESS;
	if (!microphone())
		return (FAILUER);
	if (!scythe())
		return (mutex_free(microphone(), 1), FAILUER);
	timer();
	while (i < n)
	{
		if (pthread_create(&philo[i].thread, NULL, life_manage, &philo[i]))
		{
			flag = FAILUER;
			break ;
		}
		i++;
	}
	philos_join(philo, i);
	mutex_free(forks, n);
	mutex_free(microphone(), 1);
	mutex_free(scythe(), 1);
	return (flag);
}

static void	philos_join(t_philos *philo, int n)
{
	int	i;

	i = 0;
	while (i < n)
		pthread_join(philo[i++].thread, NULL);
	free(philo);
	return ;
}

static void	mutex_free(pthread_mutex_t *mutex, int n)
{
	int	i;

	i = 0;
	while (i < n)
		pthread_mutex_destroy(&mutex[i++]);
	free(mutex);
	return ;
}
