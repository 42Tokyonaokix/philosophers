/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_perlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:33:54 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/17 22:27:44 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	count_flag(const char *str)
{
	size_t	count;

	count = 0;
	while (detect_flag(str[count]))
		count++;
	return (count);
}

size_t	count_width(const char *str)
{
	size_t	count;

	count = 0;
	if ('1' <= str[count] && str[count] <= '9')
		count++;
	while (detect_width(str[count]))
		count++;
	return (count);
}

size_t	count_precision(const char *str)
{
	size_t	count;

	count = 0;
	if (str[count] == '.')
	{
		count++;
		while ('0' <= str[count] && str[count] <= '9')
			count++;
	}
	return (count);
}

size_t	percent_len(const char *percent)
{
	size_t	index;

	index = 0;
	index += count_flag(percent);
	percent += count_flag(percent);
	index += count_width(percent);
	percent += count_width(percent);
	index += count_precision(percent);
	percent += count_precision(percent);
	if (!detect_format(*percent))
		return (0);
	index++;
	return (index);
}

int	count_percent(const char *format)
{
	size_t	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count++;
			if (percent_len(format) == 0)
				return (-1);
			format += percent_len(format);
		}
		else
			format++;
	}
	return (count);
}
