# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 17:14:17 by natakaha          #+#    #+#              #
#    Updated: 2026/01/15 17:14:17 by natakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SAN_FLAGS ?=
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRCS = srcs/utils/setup.c\
	   srcs/utils/use_mutex.c\
	   srcs/utils/create_mutex.c\
	   srcs/utils/validation.c\
	   srcs/utils/print_base.c\
	   srcs/utils/pthread.c\
	   srcs/utils/gettime.c\
	   srcs/utils/flags.c\
	   srcs/libft/ft_atoi.c\
	   srcs/libft/ft_bzero.c\
	   srcs/libft/ft_calloc.c\
	   srcs/libft/ft_memset.c\
	   srcs/libft/ft_putstr_fd.c\
	   srcs/libft/ft_putnbr_fd.c\
	   srcs/libft/ft_strlen.c\
	   srcs/libft/ft_strncmp.c\
	   srcs/domain/eat.c\
       srcs/domain/sleep.c\
	   srcs/domain/think.c\
	   srcs/domain/monitor.c\
	   srcs/app/life.c\
	   srcs/app/main.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(CLIANT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
