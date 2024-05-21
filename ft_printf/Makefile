# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 15:32:10 by soel-mou          #+#    #+#              #
#    Updated: 2024/01/08 15:32:12 by soel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_printf.c \
		print_ptr.c \
		print_un.c \
		print_str.c \
		print_int.c \
		print_char.c \
		print_hex.c \
		ft_helper.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all