#include "../libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*mapi;

	mapi = ft_strdup(s);
	index = 0;
	while (mapi[index])
	{
		mapi[index] = f(index, mapi[index]);
		index++;
	}
	return (mapi);
}

//char to_upper_if_even(unsigned int i, char c)
//{
//    if (i % 1 == 0)
//        if ('A' <= c && c <= 'Z')
//    		c += 32;
//    return (c);
//}

//int main(void)
//{
//	printf("%s", ft_strmapi("ABCDEFG", to_upper_if_even));
//}

