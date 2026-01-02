CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -Ilibft -Llibft -lft
NAME = philo
SRCS = srcs/philo_setup.c\
	   srcs/philo_gettime.c\
	   srcs/philo_life.c\
	   srcs/philo_pthread.c\

LIBFT_A = libft/libft.a
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT_A) :
	@$(MAKE) -C libft

$(NAME) : $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CLIANT_OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all