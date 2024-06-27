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

t_game *g_game;

int	detect_key_inputs(int key)
{
	static int	input_counter = 0;

	input_counter++;
	ft_printf("Input %d = %d\n", input_counter, key);
	if (key == 65307)
		clean_exit(0, &g_game);
	return (1);
}

int	detect_close()
{
	clean_exit(0, &g_game);
	return (1);
}

// int	render_frame(t_game *game)
// {
// 	im1 = mlx_xpm_file_to_image(mlx, "sprites/background.xpm", &x, &y);
// 	im2 = mlx_xpm_file_to_image(mlx, "sprites/wall.xpm", &x, &y);
// 	mlx_put_image_to_window(mlx, win1, im1, 0, 0);
// }

void load_sprites(t_game **game)
{
	t_game *root;
	int	i;

	root = *game;
	root->sprites = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/background.xpm", &i, &i));
	if (!root->sprites)
		clean_exit(3, game);
	root->sprites->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/wall.xpm", &i, &i));
	if (!root->sprites->next)
		clean_exit(3, game);
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
	g_game->win = mlx_new_window(g_game->mlx, g_game->mx * 32, g_game->my * 32, "win");
	if (!(g_game->win))
		clean_exit(2, &g_game);
	load_sprites(&g_game);
	mlx_key_hook(g_game->win, detect_key_inputs, 0);
	mlx_hook(g_game->win, 17, 0, detect_close, NULL);
	mlx_put_image_to_window(g_game->mlx, g_game->win, g_game->sprites->content, 0, 0);
	mlx_put_image_to_window(g_game->mlx, g_game->win, g_game->sprites->next->content, 0, 0);
	mlx_put_image_to_window(g_game->mlx, g_game->win, g_game->sprites->next->content, 32, 0);
	mlx_put_image_to_window(g_game->mlx, g_game->win, g_game->sprites->next->content, 64, 0);
	// idea of how its meant to work later on:
	// have an image buffer load all the sprites
	// then put that image onto the window, making sure to wipe any previous images
	// after that clear the buffer and start from the beginning.
	// I originally thought u could put an image in another image, but it seems as though that isnt possible
	// im going to have to find a way to make the buffer, then print that onto the window.
	g_game->status = 1;
	mlx_loop(g_game->mlx);
	return (1);
}
