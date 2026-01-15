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
SRCS = srcs/philo_setup.c\
	   srcs/philo_gettime.c\
	   srcs/philo_life.c\
	   srcs/philo_pthread.c\
	   srcs/philo_utils.c\

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