# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivmolina <ivmolina@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:47:59 by ivmolina          #+#    #+#              #
#    Updated: 2022/02/07 17:43:55 by ivmolina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_base.c ft_strlen.c ft_putnbr_base_n.c main.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -I.

NAME = libftprintf.a

RM = rm -f

$(NAME): $(OBJS)
			ar rcs $(NAME) $(OBJS)
all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re