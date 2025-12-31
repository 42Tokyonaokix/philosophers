/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:28:05 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/27 22:42:11 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	display_percent(size_t pindex,
	char **arglist, t_flag *flaglist)
{
	int	charcount;

	charcount = 0;
	if (flaglist[pindex].format != 'c'
		&& flaglist[pindex].format != '%')
		charcount = ft_putstr_int(arglist[pindex], 1);
	else if (flaglist[pindex].format == '%')
		charcount = ft_putchar_int(arglist[pindex][0], 1);
	else
		charcount = display_c(arglist[pindex], flaglist[pindex]);
	return (charcount);
}

static int	display_and_count(const char *format,
	char **arglist, t_flag *flaglist)
{
	size_t	pindex;
	int		charcount;
	int		sum;

	pindex = 0;
	sum = 0;
	while (*format)
	{
		charcount = 0;
		if (*format == '%')
		{
			charcount = display_percent(pindex, arglist, flaglist);
			format++;
			format += percent_len(format);
			pindex++;
		}
		else
			charcount = ft_putchar_int(*format++, 1);
		if (charcount < 0)
			break ;
		sum += charcount;
	}
	free_arglist(arglist, pindex);
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	**arglist;
	size_t	sum;
	char	**formlist;
	t_flag	*flaglist;

	if (count_percent(format) < 0)
		return (0);
	formlist = split_percent(format);
	flaglist = management_flaglist(format, formlist);
	free_formlist(formlist, count_percent(format));
	va_start(args, format);
	arglist = management_arglist(args, format, flaglist);
	if (arglist == NULL)
		return (0);
	sum = display_and_count(format, arglist, flaglist);
	free(flaglist);
	va_end(args);
	return (sum);
}

//#include <stdio.h>

//int main(void)
//{
//	ft_printf("abcdeavoh%-10.3s   fiuhu\n", "10sdfghj");
//}

//int	main(void)
//{
//	ft_printf("%c\n", 'c');
//	printf("%c\n", 'c');
//	ft_printf("%c\n", '\0');
//	printf("%c\n", '\0');
//	ft_printf("%s\n", "strings");
//	printf("%s\n", "strings");
//	ft_printf("NULL %s NULL\n", NULL);
//	printf("NULL %s NULL\n", NULL);
//	ft_printf("%s\n", "");
//	printf("%s\n", "");
//	ft_printf("%d\n", 0);
//	printf("%d\n", 0);
//	ft_printf("%d\n", -1);
//	printf("%d\n", -1);
//	ft_printf("%d\n", 105);
//	printf("%d\n", 105);
//	ft_printf("%x\n", 127);
//	printf("%x\n", 127);
//	ft_printf("%X\n", 127);
//	printf("%X\n", 127);
//	char *s = "abcde";
//	ft_printf("%p\n", s);
//	ft_printf("%p\n", s);
//	ft_printf("%p\n", NULL);
//	ft_printf("%p\n", NULL);
//}

//int	main(void)
//{
	//ft_printf("%10c\n", 'c');
	//printf("%10c\n", 'c');
	//ft_printf("%-10c\n", 'c');
	//printf("%-10c\n", 'c');
	//ft_printf("%20.0s\n", "strings");
	//printf("%20.0s\n", "strings");
	//ft_printf("%-10.3s\n", "strings");
	//printf("%-10.3s\n", "strings");
//	ft_printf("%-10.0s\n", "strings");
//	printf("%-10.0s\n", "strings");
	//ft_printf("%-10.5s\n", NULL);
	//printf("%-10.5s\n", NULL);
//	ft_printf("0123456789%7.6s0123456789\n", NULL);
//	printf("0123456789%7.6s0123456789\n", NULL);
//	ft_printf("0123456789%6.5s0123456789\n", NULL);
//	printf("0123456789%6.5s0123456789\n", NULL);
	//ft_printf("%5s\n", "");
	//printf("%5s\n", "");
	//ft_printf("%-10d\n", 0);
	//printf("%-10d\n", 0);
	//ft_printf("%10.5d\n", -1234);
	//printf("%10.5d\n", -1234);
//	ft_printf("%-10d\n", 11);
//	printf("%-10d\n", 11);
//	ft_printf("%0-10d\n", 11);
//	printf("%0-10d\n", 11);
//	ft_printf("% 10d\n", 1);
//	printf("% 10d\n", 1);
//	ft_printf("% 010d\n", 1);
//	printf("% 010d\n", 1);
//	ft_printf("% 10d\n", 1);
//	printf("% 10d\n", 1);
//	ft_printf("% +d\n", 105);
//	printf("% +d\n", 105);
//	ft_printf("% +10.5d\n", 105);
//	printf("% +10.5d\n", 105);
//	ft_printf("% 010.0d\n", 105);
//	printf("% 010.0d\n", 105);
//	ft_printf("%#7x\n", 127);
//	printf("%#7x\n", 127);
//	ft_printf("%010.0X\n", 127);
//	printf("%010.0X\n", 127);
//	char *s = "abcde";
//	ft_printf("%10p\n", s);
//	ft_printf("%10p\n", s);
//	ft_printf("%.10p\n", s);
//	ft_printf("%.10p\n", s);
//	ft_printf("%#7p\n", NULL);
//	ft_printf("%#7p\n", NULL);
//	ft_printf("%k");
//	printf("%k");
//}

//int main(void)
//{
//	ft_printf("%5%\n");
//	printf("%5%\n");
//	ft_printf("%-5%\n");
//	printf("%-5%\n");
//	ft_printf("%.03s\n", NULL);
//	printf("%.03s\n", NULL);
//	ft_printf("%3.1s\n", NULL);
//	printf("%3.1s\n", NULL);
//	ft_printf("%9.1s\n", NULL);
//	printf("%9.1s\n", NULL);
//	ft_printf("%-3.1s\n", NULL);
//	printf("%-3.1s\n", NULL);
//	ft_printf("%-9.1s\n", NULL);
//	printf("%-9.1s\n", NULL);
//	ft_printf("%.0i\n", 1);
//	printf("%.0i\n", 1);
//	ft_printf("%.i\n", 0);
//	printf("%.i\n", 0);
//	ft_printf("%5.0i\n", 0);
//	printf("%5.0i\n", 0);
//	ft_printf("%5.i\n", 0);
//	printf("%5.i\n", 0);
//	ft_printf("%-5.0i\n", 0);
//	printf("%-5.0i\n", 0);
//	ft_printf("%-5.i\n", 0);
//	printf("%-5.i\n", 0);
//	ft_printf("%.0d\n", 0);
//	printf("%.0d\n", 0);
//	ft_printf("%.d\n", 0);
//	printf("%.d\n", 0);
//	ft_printf("%5.0d\n", 0);
//	printf("%5.0d\n", 0);
//	ft_printf("%5.d\n", 0);
//	printf("%5.d\n", 0);
//	ft_printf("%-5.0d\n", 0);
//	printf("%-5.0d\n", 0);
//	ft_printf("%-5.d\n", 0);
//	printf("%-5.d\n", 0);
//}