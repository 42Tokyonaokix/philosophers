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
CFLAGS = -Wall -Wextra -Werror
NAME = philo

SRCS = srcs/main.c\
	   srcs/philo_life.c\
	   srcs/philo_setup.c\
	   srcs/utils1.c\
	   srcs/utils2_life.c\
	   srcs/utils3_print.c\
	   srcs/utils4_gettime.c\

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