# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 15:52:49 by dbozic            #+#    #+#              #
#    Updated: 2024/06/19 15:52:52 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
MAIN = so_long.c
SOURCES = map_checker.c map_checker_helper_functions.c map_functions.c \
		  struct_functions.c game_functions.c game_functions2.c
OBJECTS = $(SOURCES:%.c=%.o)
NAME = so_long.a
PROGRAM = so_long
LIBFT = Libft/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a

all: $(PROGRAM)

$(LIBFT):
	$(MAKE) -C Libft

$(MINILIBX):
	$(MAKE) -C minilibx-linux

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(PROGRAM): $(MINILIBX) $(LIBFT) $(NAME)
	$(CC) $(FLAGS) $(MAIN) $(NAME) $(LIBFT) $(MINILIBX) -lXext -lX11 -o $(PROGRAM)

%.o: %.c
	$(CC) $(FLAGS) -I. -o $@ -c $<

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	$(MAKE) -C Libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME) $(PROGRAM) $(BPROGRAM)
	$(MAKE) -C Libft fclean
	$(MAKE) -C minilibx-linux clean

cc:
	$(CC) $(FLAGS) $(MAIN) $(NAME) $(LIBFT) $(MINILIBX) -lXext -lX11 -o $(PROGRAM)

re: fclean all

full: all clean
	clear
