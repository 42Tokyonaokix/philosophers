/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:24:44 by natakaha          #+#    #+#             */
/*   Updated: 2026/01/25 05:48:45 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	*microphone(void)
{
	static pthread_mutex_t	*mic;

	if (!mic)
		mic = setup_mutex(1);
	if (!mic)
		return (NULL);
	return (mic);
}

int	print_state(int tag, char *str)
{
	pthread_mutex_t	*mic;
	static int		flag;

	mic = microphone();
	if (!mic)
		return (FAILUER);
	if (pthread_mutex_lock(mic))
		return (FAILUER);
	if (!tag)
		flag = DEATH;
	if (flag == DEATH)
	{
		pthread_mutex_unlock(mic);
		return (FAILUER);
	}
	printf("%d %d %s\n", timer(), tag, str);
	if (!ft_strncmp(str, "died", 5))
		flag = DEATH;
	pthread_mutex_unlock(mic);
	return (SUCCESS);
}
