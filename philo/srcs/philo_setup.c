/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:33:04 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/15 17:31:43 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_philos *node, char **argv, int i)
{
	node->num = ft_atoi(argv[1]);
	node->die = ft_atoi(argv[2]);
	node->death_time = node->die;
	node->eat = ft_atoi(argv[3]);
	node->slp = ft_atoi(argv[4]);
	node->tag = i + 1;
	node->eat_n = 0;
	if (node->tag == node->num)
		node->group = node->tag / 2;
	else
		node->group = (node->tag + 1) / 2;
	if (!argv[5])
		node->must = -1;
	else
	{
		if (ft_atoi(argv[5]) < 0)
			return (FAILUER);
		node->must = ft_atoi(argv[5]);
	}
	if (node->num <= 1 || node->die < 0 || node->eat < 0 || node->slp < 0)
		return (FAILUER);
	return (SUCCESS);
}

t_philos	*setup_philos(int n, char **argv)
{
	t_philos	*philos;
	int			i;

	if (n == 0)
		return (NULL);
	philos = (t_philos *)ft_calloc(sizeof(t_philos), n + 1);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (init_philo(&philos[i], argv, i) == FAILUER)
		{
			ft_putendl_fd("invlalid argument", 2);
			return (free(philos), NULL);
		}
		i++;
	}
	return (philos);
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

t_philos	*set_philo_fork(int n, char **argv, pthread_mutex_t *forks)
{
	t_philos	*philos;
	int			i;

	philos = setup_philos(n, argv);
	microphone();
	timer();
	if (!philos)
		return (NULL);
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

int	create_and_join(int n, t_philos *philo, void *(*f)(void *),
		pthread_mutex_t *forks)
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
	while (i--)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(microphone());
	free(philo);
	free(forks);
	free(microphone());
	(void)forks;
	return (SUCCESS);
}

/*tester*/

// void	*hello_world(void *arg)
//{
//	t_philos	philo;

//	philo = *(t_philos *)arg;
//	while (timer() < philo.tag * 100)
//		;
//	ft_putstr_fd("I am", 1);
//	ft_putnbr_fd(philo.tag, 1);
//	ft_putendl_fd("th philosopher", 1);
//	return (NULL);
//}
