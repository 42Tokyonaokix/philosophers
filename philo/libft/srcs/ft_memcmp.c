#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p1;
	unsigned const char	*p2;
	size_t			count;

	p1 = (unsigned const char *)s1;
	p2 = (unsigned const char *)s2;
	count = 0;
	while (count < n)
	{
		if (p1[count] != p2[count])
			return(p1[count] - p2[count]);
        count++;
	}
    return(0);
}