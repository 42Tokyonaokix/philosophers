#include "../libft.h"

void ft_putstr_fd(char *s, int fd)
{
	write(fd, s , ft_strlen(s));
}

//int main(int argc, char **argv)
//{
//	int	fd;

//	fd = open(argv[1], O_WRONLY);
//	ft_putstr_fd(argv[2], fd);
//	(void)argc;
//	(void)argv;
//}