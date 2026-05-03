/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 07:07:03 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	philo_sleep(t_system *system, t_philo *philo)
{
	int flag;
	int	ms_start;

	flag = SUCCESS;
	ms_start = get_time(system->ms_zero);
	flag |= philo_mutex_do(philo, system->print_mutex,
		print_str, (void *)"is sleeping");
	if (flag == FATAL)
		return (FATAL);
	wait_until_time(system->ms_zero, ms_start + system->time_to_sleep, USLEEP);
	return (flag)
}
