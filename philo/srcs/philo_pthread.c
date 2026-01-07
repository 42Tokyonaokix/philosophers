/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/07 00:46:28 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static pthread_mutex_t	*microphone(void)
{
	static pthread_mutex_t	*mic;

	if (!mic)
		mic = setup_mutex(1);
	if (!mic)
		return (NULL);
	return (mic);
}

int	have_forks(t_philos philo,
	pthread_mutex_t *first,
	pthread_mutex_t *next)
{
	if (!pthread_mutex_lock(first))
	{
		print_state(timer(), philo.tag, "has taken a fork");
		pthread_mutex_lock(next);
		print_state(timer(), philo.tag, "has taken a fork");
		return (SUCCESS);
	}
	return (FAILUER);
}

int	print_state(int time, int tag, char *str)
{
	pthread_mutex_t	*mic;
	static int		flag;

	mic = microphone();
	if (!mic)
		return (FAILUER);
	if (pthread_mutex_lock(mic))
		return (FAILUER);
	if (flag == DEATH)
	{
		pthread_mutex_unlock(mic);
		return (FAILUER);
	}
	ft_printf("timestamp_in_%d %d %s\n", time, tag, str);
	if (!ft_strncmp(str, "died", 5))
		flag = DEATH;
	pthread_mutex_unlock(mic);
	return (SUCCESS);
}
