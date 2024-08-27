# # Source files
# SRCC = client.c ft_helper.c
# SRCS = server.c ft_helper.c

# # Object files
# OBJC = $(SRCC:.c=.o)
# OBJS = $(SRCS:.c=.o)

# # Compiler and flags
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# # Executable names
# SERVER = server
# CLIENT = client

# # Default target
# all: $(SERVER) $(CLIENT)

# # Server executable
# $(SERVER): $(SRCS)
# 	$(CC) $(CFLAGS) $(SRCS) -o $(SERVER)

# # Client executable
# $(CLIENT): $(SRCC)
# 	$(CC) $(CFLAGS) $(SRCC) -o $(CLIENT)

# # Clean up object files
# clean:
# 	rm -f $(OBJC) $(OBJS)

# # Clean up object files and binaries
# fclean: clean
# 	rm -f $(SERVER) $(CLIENT)

# # Rebuild the project
# re: fclean all



SRCC=client.c ft_helper.c
SRCCB=client_bonus.c ft_helper.c

OBJC = $(SRCC:.c=.o)
OBJCB = $(SRCCB:.c=.o)

SRCS=server.c
SRCSB=server_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all:$(SERVER) $(CLIENT)

$(SERVER): $(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o server

$(SERVER_BONUS): $(SRCSB)
			$(CC) $(CFLAGS) $(SRCSB) -o server_bonus

$(CLIENT): $(SRCC)
			$(CC) $(CFLAGS) $(SRCC) -o client

$(CLIENT_BONUS): $(SRCCB)
			$(CC) $(CFLAGS) $(SRCCB) -o client_bonus
clean: 
		rm -rf $(OBJC) $(OBJS)
		rm -rf $(OBJCB) $(OBJSB) 

fclean: clean
		rm -rf $(SERVER) $(CLIENT)
		rm -rf $(SERVER_BONUS) $(CLIENT_BONUS)

re :fclean all
bonus:$(SERVER_BONUS) $(CLIENT_BONUS)