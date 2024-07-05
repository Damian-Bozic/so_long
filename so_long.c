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

static int	detect_close(void)
{
	clean_exit(0, &g_game);
	return (1);
}

static int	detect_key_inputs(int key, int x, int y)
{
	static int	input_counter = 0;
	static int	flag = 0;

	if (key == 65307)
		clean_exit(0, &g_game);
	if (key == -1)
		flag = -1;
	if (flag >= 0)
	{
		input_counter++;
		find_char_on_map(g_game->map, "PASD", &x, &y);
		move_player(key, g_game->map, x, y);
		if (flag == 0 && count_tiles('c', g_game->map) == 0)
		{
			find_char_on_map(g_game->map, "e", &x, &y);
			g_game->map[y][x] = 'E';
			flag = 1;
		}
		draw_frame(g_game->map, g_game, input_counter);
		if (flag == -1)
			mlx_string_put(g_game->mlx, g_game->win, (((g_game->mx * 32) / 2)
					- 22), ((g_game->my * 32) / 2), 2147483647, "You Won!");
	}
	return (1);
}

void	game_win(void)
{
	int	x;
	int	y;

	find_char_on_map(g_game->map, "PASD", &x, &y);
	g_game->map[y][x] = 'o';
	detect_key_inputs(-1, 0, 0);
}

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
			"win");
	if (!(g_game->win))
		clean_exit(2, &g_game);
	load_sprites(g_game);
	mlx_key_hook(g_game->win, detect_key_inputs, 0);
	mlx_hook(g_game->win, 17, 0, detect_close, NULL);
	g_game->status = 1;
	mlx_loop(g_game->mlx);
	return (1);
}
