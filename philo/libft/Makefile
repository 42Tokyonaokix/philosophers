# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/28 20:24:26 by natakaha          #+#    #+#              #
#    Updated: 2025/12/28 20:24:26 by natakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = srcs/ft_atoi.c\
       srcs/ft_bzero.c\
	   srcs/ft_isalnum.c\
	   srcs/ft_isascii.c\
	   srcs/ft_isalpha.c\
	   srcs/ft_isdigit.c\
	   srcs/ft_isprint.c\
	   srcs/ft_memchr.c\
	   srcs/ft_memcmp.c\
	   srcs/ft_memcpy.c\
	   srcs/ft_memmove.c\
	   srcs/ft_memset.c\
	   srcs/ft_strchr.c\
	   srcs/ft_strncmp.c\
	   srcs/ft_strlcat.c\
	   srcs/ft_strlcpy.c\
	   srcs/ft_strlen.c\
	   srcs/ft_strnstr.c\
	   srcs/ft_strrchr.c\
	   srcs/ft_tolower.c\
	   srcs/ft_toupper.c\
	   srcs/ft_calloc.c\
	   srcs/ft_strdup.c\
	   srcs/ft_substr.c\
	   srcs/ft_strjoin.c\
	   srcs/ft_strtrim.c\
	   srcs/ft_split.c\
	   srcs/ft_itoa.c\
	   srcs/ft_strmapi.c\
	   srcs/ft_striteri.c\
	   srcs/ft_putchar_fd.c\
	   srcs/ft_putstr_fd.c\
	   srcs/ft_putendl_fd.c\
	   srcs/ft_putnbr_fd.c\
	   srcs/ft_lstnew.c\
	   srcs/ft_lstadd_front.c\
	   srcs/ft_lstsize.c\
	   srcs/ft_lstlast.c\
	   srcs/ft_lstadd_back.c\
	   srcs/ft_lstdelone.c\
	   srcs/ft_lstclear.c\
	   srcs/ft_lstiter.c\
	   srcs/ft_lstmap.c\
	   srcs/format1_detect_percent.c\
	   srcs/format2_count_percent.c\
	   srcs/format3_execute_percent.c\
	   srcs/flags1_setting_flags.c\
	   srcs/flags2_read_format.c\
	   srcs/flags3_management_flaglist.c\
	   srcs/arg1_treat_c.c\
	   srcs/arg2_treat_s.c\
	   srcs/arg3_treat_di1.c\
	   srcs/arg3_treat_di2.c\
	   srcs/arg3_treat_di3.c\
	   srcs/arg4_return_bases.c\
	   srcs/arg5_treat_lx.c\
	   srcs/arg6_treat_p.c\
	   srcs/arg7_treat_u.c\
	   srcs/arg8_treat_x.c\
	   srcs/manage1_manage_format.c\
	   srcs/manage2_free_lists.c\
	   srcs/ft_printf.c\
	   srcs/util_ft_atoi_alpha.c\
	   srcs/util_ft_itoa_hexb.c\
	   srcs/util_ft_itoa_hexs.c\
	   srcs/util_ft_itoa_unsigned.c\
	   srcs/util_ft_itoa.c\
	   srcs/util_printf.c\
	   srcs/ft_strchr_len.c\
	   srcs/ft_strndup.c


OBJS = $(SRCS:.c=.o)
INCS = -I includes

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) all

.PHONEY: all clean fclean re