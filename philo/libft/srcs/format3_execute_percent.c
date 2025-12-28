/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:38:38 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:28:06 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	**malloc_persection(const char *format)
{
	char	**formlist;
	size_t	per_nbr;

	per_nbr = count_percent(format);
	if (count_percent(format) == -1)
		return (NULL);
	formlist = (char **)malloc(sizeof(char *) * (per_nbr + 1));
	if (!formlist)
		return (NULL);
	return (formlist);
}

static char	*ft_strndup(const char *str, size_t n)
{
	size_t	count;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	count = 0;
	while (count < n)
	{
		dest[count] = str[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

static char	**allocate_persection(const char *format, char **formlist)
{
	size_t	count;
	size_t	perlen;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			perlen = percent_len(format);
			formlist[count] = ft_strndup(format, perlen);
			if (!formlist[count])
			{
				free_formlist(formlist, count);
				return (NULL);
			}
			count++;
			format += perlen;
		}
		else
			format++;
	}
	return (formlist[count] = NULL, formlist);
}

char	**split_percent(const char *format)
{
	int		count;
	char	**arg_lst;

	count = count_percent(format);
	if (count < 0)
		return (NULL);
	arg_lst = malloc_persection(format);
	if (!arg_lst)
		return (NULL);
	arg_lst = allocate_persection(format, arg_lst);
	if (!arg_lst)
		return (NULL);
	return (arg_lst);
}
