#include "../libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c , 1);
}

//int main(int argc, char **argv)
//{
//	int	fd;

//	fd = open(argv[1], O_WRONLY);
//	ft_putchar_fd(argv[2][0], fd);
//	(void)argc;
//	(void)argv;
//}