/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/29 17:38:40 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	free_threads(pthread_t *thread, int i);

int	create_threads(int n, void *life_func(void *), void *monitor_func(void *),
		t_philo *philo)
{
	int			i;
	pthread_t	*thread;
	int			flag;

	thread = ft_calloc(n + 1, sizeof(pthread_t));
	if (!thread)
		return (fatal_error("malloc"), FAILURE);
	flag = SUCCESS;
	i = 0;
	while (i < n)
	{
		if (pthread_create(&thread[i], NULL, life_func,
				&philo[i]) != SUCCESS)
		{
			flag = FAILURE;
			fatal_error("pthread_create");
			return (free_threads(thread, i), FAILURE);
		}
		i++;
	}
	monitor_func(philo);
	if (free_threads(thread, i) != SUCCESS)
		flag = FAILURE;
	return (flag);
}

static int	free_threads(pthread_t *thread, int i)
{
	int	j;
	int	flag;

	j = 0;
	flag = SUCCESS;
	while (j < i && thread[j])
	{
		if (pthread_join(thread[j], NULL) != SUCCESS)
		{
			flag = FAILURE;
			fatal_error("pthread_join");
		}
		j++;
	}
	free(thread);
	return (flag);
}
