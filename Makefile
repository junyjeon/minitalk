# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/02/10 16:53:32 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS			=	-Wall -Werror -Wextra
LIB				=	./libft

SRC_CLIENT		=	srcs_client/client.c
SRC_SERVER		=	srcs_server/server.c

OBJS_CLIENT		=	$(SRC_CLIENT:.c=.o)
OBJS_SERVER		=	$(SRC_SERVER:.c=.o)

DEPS_CLIENT 	= 	$(SRC_CLIENT:.c=.d)
DEPS_SERVER 	= 	$(SRC_SERVER:.c=.d)

NAME			=	server client

all				:	$(NAME)

client		:	$(OBJS_CLIENT)
				make -C $(LIB)
				$(CC) $(CFLAGS) $(LIB)/libft.a $^ -o $@

server		:	$(OBJS_SERVER)
				make -C $(LIB)
				$(CC) $(CFLAGS) $(LIB)/libft.a $^ -o $@

clean		:
				$(RM) ./srcs_client/*.o ./srcs_server/*.o

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C $(LIB)

re			:	| fclean all

.PHONY		:	all clean fclean re

-include $(DEPS_SERVER) $(DEPS_CLIENT)
