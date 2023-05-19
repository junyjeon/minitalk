# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/05/19 22:08:06 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror -g2 -fsanitize=address
RM= rm -rf
SERVER= server
CLIENT= client

SERVER_SRCS = server.c utils.c utils2.c
CLIENT_SRCS = client.c utils.c utils2.c
SERVERB_SRCS = server_bonus.c utils_bonus.c utils2_bonus.c
CLIENTB_SRCS = client_bonus.c utils_bonus.c utils2_bonus.c
SERVER_OBJS= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS= $(CLIENT_SRCS:.c=.o)
SERVERB_OBJS= $(SERVERB_SRCS:.c=.o)
CLIENTB_OBJS= $(CLIENTB_SRCS:.c=.o)

ifdef WITH_BONUS
        SERVER_FILES = $(SERVERB_OBJS)
        CLIENT_FILES = $(CLIENTB_OBJS)
else
        SERVER_FILES = $(SERVER_OBJS)
        CLIENT_FILES = $(CLIENT_OBJS)
endif

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_FILES)
	@$(CC) $(CFLAGS) -o $@ $^
	
$(CLIENT): $(CLIENT_FILES)
	@$(CC) $(CFLAGS) -o $@ $^

bonus:
	@make WITH_BONUS=1 all
	
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJS) $(SERVERB_OBJS) $(CLIENT_OBJS) $(CLIENTB_OBJS)

fclean: clean
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
