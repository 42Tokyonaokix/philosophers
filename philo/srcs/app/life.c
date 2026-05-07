/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo0_life.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 05:16:13 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*philo_life_manage(void *arg)
{
	t_philo		*philo;
	t_system	*system;

	philo = (t_philo *)arg;
	system = philo->system;
	while (true)
	{
		if (philo_think(system, philo) != SUCCESS)
			return (NULL);
		if (philo_eat(system, philo) != SUCCESS)
			return (NULL);
		if (philo_sleep(system, philo) != SUCCESS)
			return (NULL);
	}
}
