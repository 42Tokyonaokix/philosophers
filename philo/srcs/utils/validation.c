/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/07 17:05:48 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	*validate_argument(int argc, char **argv)
{
	int	*num;
	int	i;
	int	tmp;

	if (argc < 5 || argc > 6)
		return ((ft_putstr_fd("INPUT: invalid arg number\n", 2)), NULL);
	num = ft_calloc(6, sizeof(int));
	if (!num)
		return (fatal_error("malloc"), NULL);
	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp <= 0)
			return (invalid_input_error(argv[i + 1]),
				free(num), NULL);
		num[i] = tmp;
		i++;
	}
	if (argc == 5)
		num[4] = -1;
	return (num);
}

void	fatal_error(char *arg)
{
	ft_putstr_fd("FATAL: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(" failed", 2);
}

void	invalid_input_error(char *arg)
{
	ft_putstr_fd("INPUT: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": invalid argumnet\n", 2);
}
