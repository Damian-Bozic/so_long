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
BMAIN = so_long_bonus.c
SOURCES = close_game.c draw_game.c setup_game.c check_game2.c check_game.c
OBJECTS = $(SOURCES:%.c=%.o)
NAME = so_long.a
PROGRAM = so_long
BPROGRAM = so_long_bonus
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

$(BPROGRAM): $(MINILIBX) $(LIBFT) $(NAME)
	$(CC) $(FLAGS) $(BMAIN) $(NAME) $(LIBFT) $(MINILIBX) -lXext -lX11 -o $(BPROGRAM)

%.o: %.c
	$(CC) $(FLAGS) -I. -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C Libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME) $(PROGRAM) $(BPROGRAM)
	$(MAKE) -C Libft fclean
	$(MAKE) -C minilibx-linux clean

cc:
	$(CC) $(FLAGS) $(MAIN) $(NAME) $(LIBFT) $(MINILIBX) -lXext -lX11 -o $(PROGRAM)
	$(CC) $(FLAGS) $(MAIN) $(NAME) $(LIBFT) $(MINILIBX) -lXext -lX11 -o $(BPROGRAM)

re: fclean all

bonus: $(BPROGRAM)

full: all clean
	clear
