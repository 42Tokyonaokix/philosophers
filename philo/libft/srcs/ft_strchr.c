#include "../libft.h"

char *ft_strchr(const char *s, int c)
{
	size_t count;
	
	count = 0;
	while (s[count - 1] || count == 0)
	{
		if (s[count] == (char)c)
			return((char *)&s[count]);
		count++;
	}
	return (NULL);
}