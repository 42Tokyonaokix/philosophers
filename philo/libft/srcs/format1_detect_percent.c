/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:32:53 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:18:54 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	detect_flag(char c)
{
	if (c == '#' || c == ' ')
		return (true);
	if (c == '+' || c == '-' || c == '0')
		return (true);
	return (false);
}

bool	detect_width(char c)
{
	if ('0' <= c && c <= '9')
		return (true);
	return (false);
}

bool	detect_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p')
		return (true);
	if (c == 'd' || c == 'i' || c == 'u')
		return (true);
	if (c == '%' || c == 'x' || c == 'X')
		return (true);
	return (false);
}
