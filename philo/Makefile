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

SRCS = srcs/app/setup.c\
	   srcs/app/validation.c\
	   srcs/app/main.c\
	   srcs/app/mutex.c\
	   srcs/app/print_base.c\
	   srcs/domain/life.c\
	   srcs/domain/eat.c\
       srcs/domain/sleep.c\
	   srcs/domain/think.c\
	   srcs/domain/monitor.c\
	   srcs/utils/pthread.c\
	   srcs/utils/mutex.c\
	   srcs/utils/gettime.c\
	   srcs/utils/ft_atoi.c\
	   srcs/utils/ft_bzero.c\
	   srcs/utils/ft_calloc.c\
	   srcs/utils/ft_memset.c\
	   srcs/utils/ft_putstr_fd.c\
	   srcs/utils/ft_putnbr_fd.c\
	   srcs/utils/ft_strlen.c\
	   srcs/utils/ft_strncmp.c\

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
