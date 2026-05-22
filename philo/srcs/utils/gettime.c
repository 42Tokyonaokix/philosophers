/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:36:33 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/22 23:01:18 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long	get_ms(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

long long	get_time(long long ms_zero)
{
	long long			ms_time;

	ms_time = get_ms();
	return (ms_time - ms_zero);
}

int	wait_until_time(long long ms_zero, long long ms_finish, int us_wait)
{
	int	ms_now;

	ms_now = get_time(ms_zero);
	if (ms_now > ms_finish)
		return (FAILURE);
	while (true)
	{
		usleep(us_wait);
		ms_now = get_time(ms_zero);
		if (ms_now >= ms_finish)
			return (SUCCESS);
	}
}

/* int	main(void)
{
	int	ms;
	int	time;

	ms = get_ms();
	usleep(500);
	time = get_time(ms);
	printf("ms:%d\ntime:%d\n",ms, time);	
}
*/