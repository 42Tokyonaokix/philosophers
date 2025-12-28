#include "../libft.h"
static bool is_set(char const c, char const *set);
static size_t	start_len(char const *s1, char const *set);
static size_t	end_len(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	total_len;
	char	*trimstr;
	size_t	start_str;
	size_t	count;

	if (ft_strlen(s1) <= start_len(s1, set) + end_len(s1, set))
		total_len = 0;
	else
		total_len = ft_strlen(s1) - start_len(s1, set) - end_len(s1, set);
	trimstr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (trimstr == NULL)
		return (NULL);
	start_str = start_len(s1,set), count = 0;
	while (count < total_len)
	{
		trimstr[count] = s1[start_str + count];
		count++;
	}
	trimstr[count] = '\0';
	return (trimstr);
}

static bool is_set(char const c, char const *set)
{
	size_t count;
	
	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (true);
		count++;
	}
	return (false);
} 

static size_t	start_len(char const *s1, char const *set)
{
	size_t count;
	
	count = 0;
	while (s1[count] && is_set(s1[count], set))
		count++;
	return (count);
}

static size_t	end_len(char const *s1, char const *set)
{
	size_t	count;
	size_t	end_str;
	
	end_str = ft_strlen(s1);
	if (end_str <= 0)
		return (0);
	count = 0;
	while (s1[end_str - count - 1] && is_set(s1[end_str - count - 1], set))
		count++;
	return (count);
}

//int main(void)
//{
//	printf("%s\n",ft_strtrim("ABCDFE", "ACDEB"));
//}