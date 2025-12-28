#include "../libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned  char	*pdest;
	unsigned  char	*psrc;
	size_t				count;

	pdest = (unsigned  char *)dest;
	psrc = (unsigned  char *)src;
	count = 0;
	while (psrc && pdest && count < n)
	{
		pdest[count] = psrc[count];
		count++;
	}
	return (pdest);
}