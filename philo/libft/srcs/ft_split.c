#include "../libft.h"

static size_t	count_words(char const *s, char c);
static char	*ft_strndup(const char *str, size_t n);
static void split_free(char **splitted, size_t index);
static char	**allocate_char(const char *s, char **splitted, char c);

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**splitted;

	words_count = count_words(s, c);
	splitted = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (splitted == NULL)
		return (NULL);
	splitted = allocate_char(s, splitted, c);
	return (splitted);
}

static char	**allocate_char(const char *s, char **splitted, char c)
{
	size_t	char_count;
	size_t	index;

	index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		char_count = 0;
		while (*(s + char_count) && *(s + char_count) != c)
			char_count++;
		splitted[index] = ft_strndup(s, char_count);
		if (splitted[index] == NULL)
		{
			split_free(splitted, index);
			return (NULL);
		}
		index++, s += char_count;
	}
	return (splitted[index] = NULL, splitted);
}

static size_t	count_words(char const *s, char c)
{
	size_t	index;
	size_t	count;

	count = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index] != c && s[index])
			index++, count++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (count);
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

static void split_free(char **splitted, size_t index)
{
	free(splitted[index]);
	while (index > 0)
	{
		index--;
		free(splitted[index]);
	}
	free(splitted);
}

//int main(void)
//{

//	char * * tab = ft_split("  tripouille  42  ", ' ');
//	printf("%s\n", tab[0]);
//	printf("%s\n", tab[1]);
//	printf("%p\n", tab[2]);
//}

//int main(void)
//{
//	printf("%s\n", ft_split("ACDBCDE", 'B')[0]);
//	printf("%s\n", ft_split("ACDBCDE", 'B')[1]);
//	printf("%p\n", ft_split("ACDBCDBEADGBDAG", 'B'));
//	printf("%s\n", ft_split("ACDBCDE", '\0')[0]);
//	printf("%p\n", ft_split("", 'B')[0]);
//	printf("%s\n", ft_split("ACDBCDE", 'T')[0]);
//}