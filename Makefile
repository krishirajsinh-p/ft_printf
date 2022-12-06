# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 03:43:02 by kpuwar            #+#    #+#              #
#    Updated: 2022/12/06 21:35:32 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_print_to_stdout.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

LIB = ar rc

%.o: %.c ft_printf.h
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIB) $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean re
