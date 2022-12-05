# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 03:43:02 by kpuwar            #+#    #+#              #
#    Updated: 2022/12/05 03:53:18 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c	ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

LIB = ar rc

%.o: %.c ft_printf.h
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean re
