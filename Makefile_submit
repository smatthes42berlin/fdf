# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_submit                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/10/05 14:26:33 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite

SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror $(INCLUDEFLAGS) 
NAME = push_swap
NAMELIBFT = libft.a
LINK= cc
CC = cc

PATHLIBFT = ./libft/
INCLUDEPATH = ./ ./libft/
INCLUDEFLAGS = $(patsubst %,-I% ,$(INCLUDEPATH))

SRC = 	main.c \
		check_input_main.c \
		check_input_only_int.c \
		check_input_only_int_utils.c \
		check_input_dupli_range.c \
		check_input_dupli_range_utils.c \
		set_up_stacks.c \
		set_up_stacks_free.c \
		set_up_stacks_init_sort_param.c \
		check_input_sorted.c \
		input_invalid_or_sorted.c \
		convert_list_to_ranks.c \
		convert_list_to_ranks_free.c \
		sort_stack_main.c \
		sort_stack_big_5.c \
		sort_stack_2.c \
		sort_stack_3.c \
		sort_stack_5.c \
		sort_stack_5_util.c \
		sort_stack_op_push.c \
		sort_stack_op_rotate.c \
		sort_stack_op_swap.c
		
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft  

$(NAME): libft $(OBJ)
	$(LINK) $(CFLAGS) -o $(NAME) $(OBJ) -L$(PATHLIBFT) -lft $(INCLUDEFLAGS) 

all: $(NAME)

$(PATHOBJ)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C libft

clean:
	make -C libft clean
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

# .PRECIOUS: $(PATHOBJ)%.o
