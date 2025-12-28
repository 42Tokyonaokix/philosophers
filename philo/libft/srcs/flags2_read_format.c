/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:43:56 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:29:18 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_flag	read_format(const char *format, t_flag flag)
{
	flag = str_to_flag(format, flag);
	format += count_flag(format);
	flag = str_to_width(format, flag);
	format += count_width(format);
	flag = str_to_precision(format, flag);
	format += count_precision(format);
	flag = str_format(format, flag);
	return (flag);
}

t_flag	*allocate_flags(char **formlist, t_flag *flaglist)
{
	size_t	count;

	count = 0;
	while (formlist[count])
	{
		flaglist[count] = read_format(formlist[count], flaglist[count]);
		count++;
	}
	return (flaglist);
}
