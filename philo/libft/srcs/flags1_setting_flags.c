/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:45:49 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:29:43 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flag	char_to_flag(char c, t_flag flag)
{
	if (c == '-')
		flag.minus = true;
	if (c == '+')
		flag.plus = true;
	if (c == ' ')
		flag.space = true;
	if (c == '#')
		flag.sharp = true;
	if (c == '0')
		flag.zero = true;
	return (flag);
}

t_flag	str_to_flag(const char *str, t_flag flag)
{
	size_t	count;

	count = 0;
	while (detect_flag(str[count]) == true)
	{
		flag = char_to_flag(str[count], flag);
		count++;
	}
	return (flag);
}

t_flag	str_to_width(const char *str, t_flag flag)
{
	size_t	atoi;

	atoi = ft_atoi_alpha(str);
	flag.width = atoi;
	return (flag);
}

t_flag	str_to_precision(const char *str, t_flag flag)
{
	size_t	atoi;

	if (*str != '.')
		return (flag);
	str++;
	atoi = ft_atoi_alpha(str);
	if (atoi == 0)
		flag.prezero = true;
	flag.precision = atoi;
	return (flag);
}

t_flag	str_format(const char *str, t_flag flag)
{
	flag.format = *str;
	return (flag);
}
