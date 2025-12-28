#include "../libft.h"

int ft_atoi(const char *nptr)
{
    size_t  count;
    int     number;
    int     neg;

    count = 0, neg = 1;
    while (nptr[count] == ' ' || (9 <=nptr[count] && nptr[count] <= 13))
        count++;
    if (nptr[count] == '+')
        count++;
    else if (nptr[count] == '-')
    {
        neg = -1;
        count++;
    }
    number = 0;
    while ('0' <= nptr[count] && nptr[count] <= '9')
    {
        number = number * 10 + (nptr[count] - '0');
        count++;
    }
    return (number * neg);
} 