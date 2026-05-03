/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:36:33 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 21:59:37 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	get_ms(void)
{
	struct timeval	tv;
	int				ms;

	gettimeofday(&tv, NULL);
	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (ms);
}

int	get_time(int ms_zero)
{
	int			ms_time;

	ms_time = get_ms();
	return (ms_time - ms_zero);
}

int	wait_time(int ms_time, int us_wait)
{
	int	ms_start;
	int ms_now;
	int	ms_finish;

	ms_now = get_ms();
	ms_start = ms_now;
	ms_finish = ms_start + ms_time;
	while (ms_finish > ms_now)
		usleep(us_wait);
	return (SUCCESS);
}

int	wait_until_time(int ms_zero, int ms_finish, int us_wait)
{
	int	ms_now;

	ms_now = get_time(ms_zero);
	if (ms_now > ms_finish)
		return (FAILURE);
	while (true)
	{
		usleep(us_wait);
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