/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_flaglist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:47:50 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:28:36 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_flag	initialize_flags(t_flag flags)
{
	flags.minus = false;
	flags.plus = false;
	flags.space = false;
	flags.zero = false;
	flags.sharp = false;
	flags.prezero = false;
	flags.width = 0;
	flags.precision = 0;
	flags.format = '\0';
	return (flags);
}

static t_flag	*initialize_flaglist(const char *format, t_flag *flaglist)
{
	size_t	count;
	size_t	index;

	count = count_percent(format);
	index = 0;
	while (index <= count)
	{
		flaglist[index] = initialize_flags(flaglist[index]);
		index++;
	}
	return (flaglist);
}

static t_flag	*malloc_flaglist(const char *format)
{
	t_flag	*flaglist;
	size_t	count;

	count = count_percent(format);
	flaglist = (t_flag *)malloc(sizeof(t_flag) * (count + 1));
	if (!flaglist)
		return (NULL);
	flaglist = initialize_flaglist(format, flaglist);
	return (flaglist);
}

t_flag	*management_flaglist(const char *format, char **formlist)
{
	t_flag	*flaglist;

	flaglist = malloc_flaglist(format);
	if (!flaglist)
		return (NULL);
	flaglist = allocate_flags(formlist, flaglist);
	return (flaglist);
}
