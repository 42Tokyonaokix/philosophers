/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:14:43 by natakaha          #+#    #+#             */
/*   Updated: 2026/05/03 10:26:16 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	*validate_argument(int argc, char **argv)
{
	int	*num;
	int	i;
	int	tmp;

	if (argc < 5 || argc > 6)
		return (NULL);
	num = ft_calloc(sizeof(int), 6);
	if (!num)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		tmp = ft_atoi(argv[i + 1]);
		if (tmp <= 0)
			return (free(num), NULL);
		num[i] = tmp;
		i++;
	}
	if (argc == 5)
		num[4] = -1;
	return (num);
}
