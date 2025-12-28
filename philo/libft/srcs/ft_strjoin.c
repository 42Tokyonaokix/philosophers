#include "../libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	s1_count;
	size_t	s2_count;
	char	*joinstr;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joinstr = (char *)malloc(sizeof(char) * total_len);
	if (joinstr == NULL)
		return (NULL);
	s1_count = 0, s2_count = 0;
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