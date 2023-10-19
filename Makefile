# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:58:39 by smatthes          #+#    #+#              #
#    Updated: 2023/10/19 18:26:10 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $^ -> all prerequisites with spaces in between
# $@ -> filename of the target of the rule
# $< ->  name of the first prerequisite
# $(info $(ADDHEADERLOC))


# -I Flag adds path where header files are searched during preprocessing
SHELL:=/bin/bash
CFLAGS = -Wall -Wextra -Werror $(INCLUDEFLAGS) 
NAME = fdf
NAMELIBFT = libft.a
NAMELIBMLX = libmlx.a
NAMEADDLIBS = -lmlx -lXext -lX11
NAMEMATH = -lm
LINK= cc
CC = cc

PATHPROJABS = /home/smatthes/42cursus/projects42/printf/
PATHLIBFT = ./libft/
PATHLIBMLX = ./minilibx-linux/
PATHADDLIBS = /usr/include/
INCLUDEPATH = ./include/ ./libft/include/ ./minilibx-linux/ /usr/include/
INCLUDEFLAGS = $(patsubst %,-I% ,$(INCLUDEPATH))
SUBFOLDERSRC = .
BASEPATHSRC = ./src/
PATHSRC = $(patsubst %,$(BASEPATHSRC)%,$(SUBFOLDERSRC))
PATHBUILD = build/
PATHOBJ = build/obj/

VPATH = $(PATHSRC)

SRC = 	main.c \
		check_input_main.c \
		parse_map_main.c \
		parse_map_check_dimensions.c \
		parse_map_get_points.c \
		free_all_points.c \
		print_points.c \
		project_points_main.c \
		parse_map_utils.c \
		calc_points_color_main.c \
		colors.c \
		get_points_range.c \
		show_points_mlibx_main.c \
		show_points_mlibx_free.c 

		
OBJFNAME = $(SRC:.c=.o)
OBJ = $(patsubst %,$(PATHOBJ)%,$(OBJFNAME))

.PHONY: all clean fclean re libs  

$(NAME): libs $(OBJ)
	$(LINK) $(CFLAGS) -o $(NAME) $(OBJ) -L$(PATHLIBFT) -lft -L$(PATHLIBMLX) -lmlx -L$(PATHADDLIBS) $(NAMEADDLIBS) $(NAMEMATH)

all: $(NAME)

$(PATHOBJ)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libs:
	make -C $(PATHLIBFT)
	make -C $(PATHLIBMLX)

clean:
	make -C $(PATHLIBFT) clean
	make -C $(PATHLIBMLX) clean
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PRECIOUS: $(PATHOBJ)%.o
