/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 04:06:10 by natakaha          #+#    #+#             */
/*   Updated: 2025/09/09 12:48:14 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		diff;

	i = 0;
	diff = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	diff = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (diff);
}

//int main(void)
//{
//	 char	*s1 = "A";
//	 char	*s2 = "あ";

//	printf("%d\n", ft_strcmp(s1, s2));
//	printf("%d",strcmp(s1,s2));
//	return (0);
//}
