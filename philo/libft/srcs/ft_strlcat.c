#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t count;
	size_t dstlen;

	dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (ft_strlen(src) + dstsize);
	count = 0;
	while (src[count] && count + dstlen < dstsize -1)
	{
		dst[dstlen + count] = src [count];
		count++;
	}
	dst[dstlen + count] = '\0';
	return (dstlen + ft_strlen(src));
}