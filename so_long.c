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

void *sprite(t_game *root, int index)
{
	t_list *current;
	
	current = root->sprites;
	while (index > 0)
	{
		current = current->next;
		index--;
	}
	return (current->content);
}

void *node(t_game *root, int index)
{
	t_list *current;
	
	current = root->sprites;
	while (index > 0)
	{
		current = current->next;
		index--;
	}
	return (current);
}
//MAKE EXIT LOOK OPENED ONCE ALL COLLECTABLES ARE FOUND

void put_img(t_game *root, char tile, int x, int y)
{
	if (tile == 'o')
		return ;
	if (tile == '1')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 1), x, y);
	if (tile == 'c')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 2), x, y);
	if (tile == 'e')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 3), x, y);
	if (tile == 'P')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 4), x, y);
	if (tile == 'A')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 5), x, y);
	if (tile == 'S')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 6), x, y);
	if (tile == 'D')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 7), x, y);
}

void draw_frame(char **map, t_game *root, int count)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(root->mlx, root->win);
	mlx_put_image_to_window(root->mlx, root->win, root->sprites->content, 0, 0);
	while (map[y])
	{
		while (map[y][x])
		{
			put_img(root, map[y][x], x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(root->mlx, root->win, 8, 12, 2147483647, "Action Count");
	mlx_string_put(root->mlx, root->win, 8, 24, 2147483647, ft_itoa(count));
}

void find_player(char **map, int *rx, int *ry)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if ((map[y][x] == 'P') || (map[y][x] == 'A') || (map[y][x] == 'S')
				|| (map[y][x] == 'D'))
			{
				*rx = x;
				*ry = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
void move_player2(int key, char **map, int x, int y)
{

	if (key == 115)
	{
		if (map[y + 1][x] != '1' && map[y + 1][x] != 'e')
		{
			map[y][x] = 'o';
			map[y + 1][x] = 'S';
		}
		else
			map[y][x] = 'S';
	}
	else if (key == 100)
	{
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'e')
		{
			map[y][x] = 'o';
			map[y][x + 1] = 'D';
		}
		else
			map[y][x] = 'D';
	}
}

void move_player(int key, char **map, int x, int y)
{
	if (key == 119)
	{
		if (map[y - 1][x] != '1' && map[y - 1][x] != 'e')
		{
			map[y][x] = 'o';
			map[y - 1][x] = 'P';
		}
		else
			map[y][x] = 'P';
	}
	else if (key == 97)
	{
		if (map[y][x - 1] != '1' && map[y][x - 1] != 'e')
		{
			map[y][x] = 'o';
			map[y][x - 1] = 'A';
		}
		else
			map[y][x] = 'A';
	}
	else
		move_player2(key, map, x, y);
}

int	detect_key_inputs(int key)
{
	static int	input_counter = 0;
	int			x;
	int			y;

	input_counter++;
	ft_printf("Input %d = %d\n", input_counter, key);
	if (key == 65307)
		clean_exit(0, &g_game);
	// if (key == 119) //w
	// if (key == 97) //a
	// if (key == 115) //s
	// if (key == 100) //d
	find_player(g_game->map, &x, &y);
	ft_printf("found player at %d, %d\n", x, y);
	move_player(key, g_game->map, x, y);
	draw_frame(g_game->map, g_game, input_counter);
	int	i = 0;
	while (g_game->map[i])
	{
		ft_printf("%d=	%s\n", i, g_game->map[i]);
		i++;
	}
	return (1);
}

//MAKE EXIT LOOK OPENED ONCE ALL COLLECTABLES ARE FOUND

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

void load_sprites(t_game *root)
{
	int	i;

	root->sprites = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/background.xpm", &i, &i));
	if (!root->sprites)
		clean_exit(3, &root);
	root->sprites->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/wall.xpm", &i, &i));
	if (!root->sprites->next)
		clean_exit(3, &root);
	root->sprites->next->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/collect.xpm", &i, &i));
	if (!root->sprites->next->next)
		clean_exit(3, &root);
	root->sprites->next->next->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/exit.xpm", &i, &i));
	if (!root->sprites->next->next->next)
		clean_exit(3, &root);
	root->sprites->next->next->next->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/playerw.xpm", &i, &i));
	if (!root->sprites->next->next->next->next)
		clean_exit(3, &root);
	root->sprites->next->next->next->next->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/playera.xpm", &i, &i));
	if (!root->sprites->next->next->next->next->next)
		clean_exit(3, &root);
	root->sprites->next->next->next->next->next->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/players.xpm", &i, &i));
	if (!root->sprites->next->next->next->next->next->next)
		clean_exit(3, &root);
	root->sprites->next->next->next->next->next->next->next = ft_lstnew(mlx_xpm_file_to_image(root->mlx, "sprites/playerd.xpm", &i, &i));
	if (!root->sprites->next->next->next->next->next->next->next)
		clean_exit(3, &root);
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
	load_sprites(g_game);
	mlx_key_hook(g_game->win, detect_key_inputs, 0);
	mlx_hook(g_game->win, 17, 0, detect_close, NULL);
	g_game->status = 1;
	mlx_loop(g_game->mlx);
	return (1);
}
