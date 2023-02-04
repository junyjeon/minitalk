# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/01/31 21:51:24 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O3

# Define the directories
MANDATORY_DIR	=	mandatory

SRC_DIR			=	sources
INC_DIR			=	includes
BUILD_DIR		=	build

CORE_DIR		=	core

# Define the source files
SRCS_MAIN		=	main.c
SRCS_CORE		=	$(addprefix $(CORE_DIR)/, check_duplicate_and_sort.c hard_coding.c \
parsing_stack_and_array.c print_error.c push_pop.c quick_sort.c ranked.c stack_init.c)

SRCS_TOTAL		=	$(SRCS_MAIN) $(SRCS_CORE) $(SRCS_COMMAND) $(SRCS_UTIL)
SRCS_DIR		=	$(MANDATORY_DIR)/$(SRC_DIR)
INCS_DIR		=	$(MANDATORY_DIR)/$(INC_DIR)

NAME			=	push_swap

SRCS			=	$(addprefix $(SRCS_DIR)/, $(SRCS_TOTAL))
OBJS			=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS_TOTAL))
DEPS			=	$(patsubst %.c, $(BUILD_DIR)/%.d, $(SRCS_TOTAL))

all: $(NAME)

# Define the target and dependencies
$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${GREEN}> Compilation of the push_swap is success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRCS)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(DEPS)
	@rm -rf $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the so_long have been deleted ❌${END}"

fclean:
	@$(RM) $(OBJS) $(DEPS) $(LIBS) $(LIBMLX) so_long so_long_bonus
	@rm -rf $(BUILD_DIR)
	@echo "${YELLOW}> Cleaning of the so_long has been don./e ❌${END}"

re: fclean
	@make all

.PHONY:	all clean fclean re

# minimal color codes
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

-include $(DEPS)
