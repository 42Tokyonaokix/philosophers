/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2025/12/31 21:58:34 by natakaha         ###   ########.fr       */
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

int	have_a_fork(t_philos philo,
	pthread_mutex_t *first,
	pthread_mutex_t *next)
{
	if (!pthread_mutex_lock(first))
	{
		if (print_state(timer(), philo.tag, "has taken a fork") == FAILUER)
			return (FAILUER);
		if (pthread_mutex_lock(next))
			return (FAILUER);
		if (print_state(timer(), philo.tag, "has taken a fork") == FAILUER)
			return (FAILUER);
	}
	return (SUCCESS);
}

int	print_state(int time, int tag, char *str)
{
	pthread_mutex_t	*mic;
	static int		flag;

	if (flag == DEATH)
		return (FAILUER);
	mic = microphone();
	if (!mic)
		return (FAILUER);
	if (pthread_mutex_lock(mic))
		return (FAILUER);
	ft_printf("timestamp_in_%d %d %s\n", time, tag, str);
	pthread_mutex_unlock(mic);
	if (ft_strncmp(str, "died", 5))
		return (SUCCESS);
	pthread_mutex_destroy(mic);
	flag = DEATH;
	return (FAILUER);
}

