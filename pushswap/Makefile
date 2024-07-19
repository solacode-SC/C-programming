# Makefile

# Source files
SRC = main.c \
      ft_helper/get_args.c \
      movs/ft_push.c \
      movs/ft_reverse.c \
      movs/ft_rotate.c \
      movs/ft_swap.c

OBJ = $(SRC:.c=.o)

NAME = pushswap.a
OUT = pushswap

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

