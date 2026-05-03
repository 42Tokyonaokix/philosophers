/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 07:46:31 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	print_fork(t_philo *philo)
{
	return (print_str(philo, "has taken a fork"));
}

int	print_eat(t_philo *philo)
{
	return (print_str(philo, "is eating"));
}