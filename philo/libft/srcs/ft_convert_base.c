/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:58:00 by natakaha          #+#    #+#             */
/*   Updated: 2025/09/18 13:01:47 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] <= 32 || 127 <= base[i] || base[i] == 43 || base[i] == 45)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	atoi_check(char str, char *base)
{
	int	count;
	int	nbr;

	count = 0;
	nbr = 0;
	if ((9 <= str && str <= 13) || str == 32)
		return (' ');
	if (str == 43 || str == 45)
		return ('+');
	while (base[count])
		if (str == base[count++])
			return ('5');
	return ('f');
}

int	atoi_read(char *str, char *base, int i, char mode)
{
	int	neg;
	int	score;
	int	count;

	neg = 1;
	score = 0;
	while (mode == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		mode = atoi_check(str[++i], base);
	}
	while (mode == '5')
	{
		count = 0;
		while (base[count])
		{
			if (base[count] == str[i])
				score = score * ft_strlen(base) + count;
			count++;
		}
		mode = atoi_check(str[++i], base);
	}
	return (score * neg);
}

int	ft_atoi_base(char *str, char *base_from, char *base_to)
{
	char	mode;
	int		i;

	i = 0;
	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (0);
	mode = atoi_check(str[0], base_from);
	while (mode == ' ')
		mode = atoi_check(str[++i], base_from);
	return (atoi_read(str, base_from, i, mode));
}
