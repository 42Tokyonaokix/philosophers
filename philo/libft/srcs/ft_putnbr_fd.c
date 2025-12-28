#include "../libft.h"

void ft_putnbr_fd(int n, int fd)
{
	ft_putstr_fd(ft_itoa(n), fd);
}

//int main(void)
//{
//	int	fd;

//	fd = open("test1", O_WRONLY);
//	ft_putnbr_fd(12345,fd);
//}