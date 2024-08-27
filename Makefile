# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soel-mou <soel-mou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 02:04:44 by soel-mou          #+#    #+#              #
#    Updated: 2024/08/27 02:04:45 by soel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCC=client.c ft_helper.c
SRCCB=client_bonus.c ft_helper.c

OBJC = $(SRCC:.c=.o)
OBJCB = $(SRCCB:.c=.o)

SRCS=server.c ft_helper.c
SRCSB=server_bonus.c ft_helper.c

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