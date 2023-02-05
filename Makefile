# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/02/05 09:02:16 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O2

# Define the directories

SRC_DIR			=	sources
BUILD_DIR		=	build
INC_DIR			=	-I includes

# Define the source files
SRC_PARSING		=	$(addprefix parsing/, init.c parse.c print_error.c push_pop.c ranked.c)
SRC_COMMAND		=	$(addprefix command/, push.c reverse_rotate.c rotate.c swap.c)
SRC_HARDCODING	=	$(addprefix hardcoding/, hard_coding.c sort_three.c sort_four.c sort_five.c)
SRC_QUICKSORT	=	$(addprefix quicksort/, find_pivot.c partition.c quick_sort.c rotation.c)
SRC_UTIL		=	$(addprefix util/, ft_atoi_ll.c ft_lstnew.c ft_memcpy.c ft_split.c\
 ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c)

PUSHSWAP_SRCS	=	$(addprefix $(SRC_DIR)/, main.c $(SRC_PARSING) $(SRC_COMMAND) $(SRC_HARDCODING) $(SRC_QUICKSORT) $(SRC_UTIL))
PUSHSWAP_OBJS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(PUSHSWAP_SRCS))
PUSHSWAP_DEPS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(PUSHSWAP_SRCS))

PUSHSWAP		=	push_swap

all:
		@$(MAKE) -j $(PUSHSWAP)
	
# Define the target and dependencies

$(PUSHSWAP): $(PUSHSWAP_OBJS)
		@$(CC) $(CFLAGS) $^ -o $@
		@printf "${GREEN}> [PUSHSWAP] success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | dir_guard
		@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

dir_guard:
		@mkdir -p $(addprefix $(BUILD_DIR)/, parsing)
		@mkdir -p $(addprefix $(BUILD_DIR)/, command)
		@mkdir -p $(addprefix $(BUILD_DIR)/, hardcoding)
		@mkdir -p $(addprefix $(BUILD_DIR)/, quicksort)
		@mkdir -p $(addprefix $(BUILD_DIR)/, util)

clean:
		@$(RM) -r $(BUILD_DIR)
		@echo "${YELLOW}> All objects files of the push_swap have been deleted.❌${END}"

fclean:
		@$(RM) -r $(PUSHSWAP) $(BUILD_DIR) push_swap
		@echo "${YELLOW}> Cleaning of the push_swap has been done.❌${END}"

re: fclean
		@$(MAKE) all
		@printf "$(GREEN)Cleaned and rebuilt everything for pushswap!${END}"

.PHONY:	all clean fclean re dir_guard

#Colors

END				=	$'\x1b[0m
BOLD			=	$'\x1b[1m
UNDER			=	$'\x1b[4m
REV				=	$'\x1b[7m
GREY			=	$'\x1b[30m
RED				=	$'\x1b[31m
GREEN			=	$'\x1b[32m
YELLOW			=	$'\x1b[33m
BLUE			=	$'\x1b[34m
PURPLE			=	$'\x1b[35m
CYAN			=	$'\x1b[36m
WHITE			=	$'\x1b[37m

-include $(PUSHSWAP_DEPS)
