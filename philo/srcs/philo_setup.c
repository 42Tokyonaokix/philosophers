/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:33:04 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/31 21:40:08 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philo(t_philos *node, char **argv, int tag)
{
	node->num = ft_atoi(argv[1]);
	node->die = ft_atoi(argv[2]);
	node->eat = ft_atoi(argv[3]);
	node->slp = ft_atoi(argv[4]);
	node->tag = tag;
	node->eat_n = 0;
	if (!argv[5])
		node->must = -1;
	else
		node->must = ft_atoi(argv[5]);
}

t_philos	*setup_philos(int n, char **argv)
{
	t_philos	*lst;
	int			i;

	if (n == 0)
		return (NULL);
	lst = (t_philos *)ft_calloc(sizeof(t_philos), n + 1);
	if (!lst)
		return (NULL);
	i = 0;
	while (i < n)
	{
		init_philo(&lst[i], argv, i);
		i++;
	}
	return (lst);
}

pthread_mutex_t	*setup_mutex(int n)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), n + 1);
	if (!forks)
		NULL;
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&forks[i], NULL) == FAILUER)
			return (free(forks), NULL);
		i++;
	}
	return (forks);
}

t_philos	*set_philo_fork(int n, char **argv)
{
	t_philos		*philos;
	pthread_mutex_t	*forks;
	int				i;

	philos = setup_philos(n, argv);
	forks = setup_mutex(n);
	i = 0;
	while (i < n)
	{
		philos[i].left = &forks[i];
		if (i + 1 < n)
			philos[i].right = &forks[i + 1];
		else
			philos[i].right = &forks[0];
		i++;
	}
	return (philos);
}

int	create_and_join(int n, t_philos *philo, void *(*f)(void *))
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_create(&philo[i].thread, NULL, f, &philo[i]))
			return (FAILUER);
		i++;
	}
	i = 0;
	while (i < n)
		pthread_join(philo[i++].thread, NULL);
	return (SUCCESS);
}

/*tester*/

void	*hello_world(void *arg)
{
	t_philos	philo;

	philo = *(t_philos *)arg;
	while (timer() < philo.tag * 100)
		;
	ft_putstr_fd("I am", 1);
	ft_putnbr_fd(philo.tag, 1);
	ft_putendl_fd("th philosopher", 1);
	return (NULL);
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
