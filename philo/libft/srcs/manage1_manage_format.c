/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage1_manage_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:25:45 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/22 16:30:08 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	**malloc_arglist(size_t count)
{
	char	**arglist;

	arglist = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arglist)
		return (NULL);
	return (arglist);
}

static char	*allocate_argument(va_list args, t_flag flag)
{
	if (flag.format == 'c')
		return (return_c(args, flag));
	if (flag.format == 's')
		return (return_s(args, flag));
	if (flag.format == 'd' || flag.format == 'i')
		return (return_di(args, flag));
	if (flag.format == 'u')
		return (return_u(args, flag));
	if (flag.format == 'x')
		return (return_x(args, flag));
	if (flag.format == 'X')
		return (return_large_x(args, flag));
	if (flag.format == 'p')
		return (return_p(args, flag));
	if (flag.format == '%')
		return (ft_strdup("%"));
	return (NULL);
}

static char	**allocate_arglist(va_list args, char **arglist, t_flag *flaglist)
{
	size_t	count;

	count = 0;
	while (flaglist[count].format)
	{
		arglist[count] = allocate_argument(args, flaglist[count]);
		if (!arglist[count])
		{
			free_arglist(arglist, count);
			return (NULL);
		}
		count++;
	}
	arglist[count] = NULL;
	return (arglist);
}

char	**management_arglist(va_list args, const char *format, t_flag *flaglist)
{
	size_t	count;
	char	**arglist;

	count = count_percent(format);
	arglist = malloc_arglist(count);
	if (!arglist)
		return (NULL);
	arglist = allocate_arglist(args, arglist, flaglist);
	return (arglist);
}
