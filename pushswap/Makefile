# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 03:18:54 by soel-mou          #+#    #+#              #
#    Updated: 2024/08/08 03:18:54 by soel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
		ft_helper/get_args.c \
		ft_helper/helper_list.c \
		ft_helper/helper_fun.c \
		movs/ft_push.c \
		movs/ft_reverse.c \
		movs/ft_rotate.c \
		movs/ft_swap.c \
		sorting/set_algo.c \
		sorting/sorting_tools.c \
		sorting/sort_big_nums.c \
		sorting/sorting_helper.c

OBJ = $(SRC:.c=.o)

NAME = pushswap.a
OUT = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE_DIR = .

all: $(OUT)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $(OUT) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OUT)

re: fclean all

