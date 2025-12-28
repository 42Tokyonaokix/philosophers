/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:12:01 by natakaha          #+#    #+#             */
/*   Updated: 2025/09/18 13:09:40 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		base_check(char *base);
char	atoi_check(char str, char *base);
int		atoi_read(char *str, char *base, int i, char mode);
int		ft_atoi_base(char *str, char *base_from, char *base_to);

int	digit_calculation(int number, char *base_to)
{
	int	digit;

	digit = 0;
	if (number < 0)
	{
		number = -number;
		digit++;
	}
	if (number == 0)
		digit = 1;
	while (number > 0)
	{
		number = number / ft_strlen(base_to);
		digit += 1;
	}
	return (digit);
}

char	*into_char(int number, char *base_from, char *base_to)
{
	int		neg;
	int		digit;
	char	*putout;
	int		count;

	neg = 1;
	digit = digit_calculation(number, base_to);
	putout = (char *)malloc(sizeof(char) * (digit + 1));
	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (NULL);
	if (number < 0)
	{
		number = -number;
		neg = -1;
	}
	putout[digit] = '\0';
	while (digit-- > 0)
	{
		count = number % ft_strlen(base_to);
		putout[digit] = base_to[count];
		number = number / ft_strlen(base_to);
	}
	if (neg < 0)
		putout[0] = '-';
	return (putout);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		number;
	char	*display;

	number = ft_atoi_base(nbr, base_from, base_to);
	display = into_char(number, base_from, base_to);
	return (display);
}

//int main(void)
//{
//		printf("%s\n", ft_convert_base("-abcccccc", "-bc", "123-456789"));
//		printf("%s\n", ft_convert_base("bac", "abc", "0123456+789"));
//		printf("%s\n", ft_convert_base("cab", "abc", "01234569789"));
//		printf("%s\n", ft_convert_base("ab", "abc", "0123456789"));
//}
