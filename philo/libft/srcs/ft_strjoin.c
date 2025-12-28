/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 02:50:51 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/10 19:08:21 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	size_t	total_len;
//	size_t	s1_count;
//	size_t	s2_count;
//	char	*joinstr;

//	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
//	joinstr = (char *)malloc(sizeof(char) * total_len);
//	if (joinstr == NULL)
//		return (NULL);
//	s1_count = 0;
//	s2_count = 0;
//	while (s1[s1_count])
//	{
//		joinstr[s1_count + s2_count] = s1[s1_count];
//		s1_count++;
//	}
//	while (s2[s2_count])
//	{
//		joinstr[s1_count + s2_count] = s2[s2_count];
//		s2_count++;
//	}
//	joinstr[s1_count + s2_count] = '\0';
//	return (joinstr);
//}

static char	*allocate_char(char const *s1, char const *s2, char *joinstr);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*joinstr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strchr_len(s1, '\0') + ft_strchr_len(s2, '\0') + 1;
	joinstr = (char *)malloc(sizeof(char) * total_len);
	if (joinstr == NULL)
		return (NULL);
	joinstr = allocate_char(s1, s2, joinstr);
	return (joinstr);
}

static char	*allocate_char(char const *s1, char const *s2, char *joinstr)
{
	size_t	s1_count;
	size_t	s2_count;

	s1_count = 0;
	s2_count = 0;
	while (s1[s1_count])
	{
		joinstr[s1_count + s2_count] = s1[s1_count];
		s1_count++;
	}
	while (s2[s2_count])
	{
		joinstr[s1_count + s2_count] = s2[s2_count];
		s2_count++;
	}
	joinstr[s1_count + s2_count] = '\0';
	return (joinstr);
}

//int main(void)
//{
//	printf("%s\n", ft_strjoin("abc", "abc"));
//}
