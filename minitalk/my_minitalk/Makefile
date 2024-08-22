# Source files
SRCC = client.c ft_helper.c
SRCS = server.c ft_helper.c

# Object files
OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Executable names
SERVER = server
CLIENT = client

# Default target
all: $(SERVER) $(CLIENT)

# Server executable
$(SERVER): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(SERVER)

# Client executable
$(CLIENT): $(SRCC)
	$(CC) $(CFLAGS) $(SRCC) -o $(CLIENT)

# Clean up object files
clean:
	rm -f $(OBJC) $(OBJS)

# Clean up object files and binaries
fclean: clean
	rm -f $(SERVER) $(CLIENT)

# Rebuild the project
re: fclean all
