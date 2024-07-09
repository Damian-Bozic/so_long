/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:39:55 by dbozic            #+#    #+#             */
/*   Updated: 2024/06/19 15:40:03 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game		*g_game;

// find_char_on_map searches the map for the first occurance of one of the
//  characters inside *str, then sets its X and Y coordinates.
static void	find_char_on_map(char **map, char *str, int *x, int *y)
{
	int	i;

	i = 0;
	*x = 0;
	*y = 0;
	while (map[*y])
	{
		while (map[*y][*x])
		{
			while (str[i])
			{
				if (map[*y][*x] == str[i])
					return ;
				i++;
			}
			i = 0;
			*x = *x + 1;
		}
		*x = 0;
		*y = *y + 1;
	}
}

// detect_close runs when the close window X is clicked.
static int	detect_close(void)
{
	clean_exit(0, &g_game);
	return (1);
}

// detect_key_inputs runs whenever a key is pressed on the keyboard.
// each time a key is pressed the screen renders a new image.
// if a movement key is pressed the player will move.
// this function manages game->status which keeps track of whether the
//  exit is open or the game is complete, aswell as keeping track of
//  total player moves.
// if the key is 'esc' then the game closes.
static int	detect_key_inputs(int key, int x, int y)
{
	if (key == 65307)
		clean_exit(0, &g_game);
	if (key == -1)
	{
		g_game->status = -1;
		g_game->moves++;
		ft_printf("Total Movements: %d\n", g_game->moves);
	}
	if (g_game->status >= 0)
	{
		find_char_on_map(g_game->map, "PASD", &x, &y);
		if (move_player(key, g_game->map, x, y))
		{
			g_game->moves++;
			ft_printf("Total Movements: %d\n", g_game->moves);
		}
		if (g_game->status == 0 && count_tiles('c', g_game->map) == 0)
		{
			find_char_on_map(g_game->map, "e", &x, &y);
			g_game->map[y][x] = 'E';
			g_game->status = 1;
		}
		draw_frame(g_game, g_game->moves, g_game->status, 0);
	}
	return (1);
}

// game_win removes the player from the map and calls detect_key_inputs
//  with -1, which then sets the game as finished.
void	game_win(void)
{
	int	x;
	int	y;

	find_char_on_map(g_game->map, "PASD", &x, &y);
	g_game->map[y][x] = '0';
	detect_key_inputs(-1, 0, 0);
}

// main checks the input, makes the game structure, initializes the mlx,
//  setsup a new mlx window, loads sprites, before setting up a keyboard hook,
//  and a window close hook, then finally enters an infinite loop.
int	main(int argc, char **argv)
{
	g_game = NULL;
	if (argc != 2)
		clean_exit(4, &g_game);
	check_file_type(argv[1]);
	g_game = make_game_struct();
	if (!g_game)
		return (0);
	g_game->map = create_map(argv[1], &g_game);
	g_game->mlx = mlx_init();
	if (!(g_game->mlx))
		clean_exit(1, &g_game);
	g_game->win = mlx_new_window(g_game->mlx, g_game->mx * 32, g_game->my * 32,
			"Bit Byte");
	if (!(g_game->win))
		clean_exit(2, &g_game);
	load_sprites(g_game);
	mlx_key_hook(g_game->win, detect_key_inputs, 0);
	mlx_hook(g_game->win, 17, 0, detect_close, NULL);
	draw_frame(g_game, g_game->moves, g_game->status, 0);
	mlx_loop(g_game->mlx);
	return (1);
}
