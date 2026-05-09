/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/09 10:48:23 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	print_str(t_philo *philo, void *ptr)
{
	t_system	*system;
	int			ms_now;
	char		*str;
	int			flag;

	str = (char *)ptr;
	system = philo->system;
	flag = philo_mutex_do(philo, system->dead_mutex, are_philos_living, system);
	if (ft_strncmp(str, "died", 5) != 0 && flag != SUCCESS)
		return (flag);
	ms_now = get_time(system->ms_zero);
	ft_putnbr_fd(ms_now, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putnbr_fd(philo->id, STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putstr_fd(str, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (SUCCESS);
}

int	are_philos_living(t_philo *philo, void *arg)
{
	t_system	*system;

	system = (t_system *)arg;
	return (system->philos_state);
	(void)philo;
}
