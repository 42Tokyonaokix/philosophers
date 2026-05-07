/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 00:10:03 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

pthread_mutex_t	*create_mutex(int n)
{
	pthread_mutex_t	*mutex;
	int				i;

	mutex = ft_calloc(n + 1, sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&mutex[i], NULL) != SUCCESS)
		{
			free_mutex(mutex, i);
			return (NULL);
		}
		i++;
	}
	return (mutex);
}

int	free_mutex(pthread_mutex_t *mutex, int i)
{
	int	j;
	int	flag;

	flag = SUCCESS;
	j = 0;
	while (j < i)
	{
		if (pthread_mutex_destroy(&mutex[j]) != SUCCESS)
			flag = FAILURE;
		j++;
	}
	free(mutex);
	return (flag);
}
