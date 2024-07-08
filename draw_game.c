/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:35:09 by dbozic            #+#    #+#             */
/*   Updated: 2024/07/08 14:35:20 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// sprite scrolls through the asset list and returns the img based on the index.
static void	*sprite(t_game *root, int index)
{
	t_list	*current;

	current = root->sprites;
	while (index > 0)
	{
		current = current->next;
		index--;
	}
	return (current->content);
}

// put_img finds what tile is on the given coordinate, then draws the
//  according sprite on that possition.
static void	put_img(t_game *root, char tile, int x, int y)
{
	if (tile == 'o')
		return ;
	else if (tile == '1')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 1), x, y);
	else if (tile == 'c')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 2), x, y);
	else if (tile == 'e')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 3), x, y);
	else if (tile == 'P')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 4), x, y);
	else if (tile == 'A')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 5), x, y);
	else if (tile == 'S')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 6), x, y);
	else if (tile == 'D')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 7), x, y);
	else if (tile == 'E')
		mlx_put_image_to_window(root->mlx, root->win, sprite(root, 8), x, y);
}

// draw_frame clears the window, then starts drawing sprites according to
//  the map then prints the amount of moves in the top right of the window.
// if the status of the game is -1 (meaning that the game has been won)
//  it prints "You Won!" on the centre of the screen.
void	draw_frame(t_game *root, int count, int status, int y)
{
	char	*str;
	int		x;

	x = 0;
	mlx_clear_window(root->mlx, root->win);
	mlx_put_image_to_window(root->mlx, root->win, root->sprites->content, 0, 0);
	while (root->map[y])
	{
		while (root->map[y][x])
		{
			put_img(root, root->map[y][x], x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_string_put(root->mlx, root->win, 8, 12, 2147483647, "Action Count");
	str = ft_itoa(count);
	if (!str)
		clean_exit(-1, &root);
	mlx_string_put(root->mlx, root->win, 8, 24, 2147483647, str);
	if (status == -1)
		mlx_string_put(root->mlx, root->win, (((root->mx * 32) / 2)
				- 22), ((root->my * 32) / 2), 2147483647, "You Won!");
	free(str);
}

static int	move_player2(int key, char **map, int x, int y)
{
	if (key == 115)
	{
		map[y][x] = 'S';
		if (map[y + 1][x] == 'E')
			game_win();
		else if (map[y + 1][x] != '1' && map[y + 1][x] != 'e')
		{
			map[y][x] = 'o';
			map[y + 1][x] = 'S';
			return (1);
		}
	}
	else if (key == 100)
	{
		map[y][x] = 'D';
		if (map[y][x + 1] == 'E')
			game_win();
		else if (map[y][x + 1] != '1' && map[y][x + 1] != 'e')
		{
			map[y][x] = 'o';
			map[y][x + 1] = 'D';
			return (1);
		}
	}
	return (0);
}

// move_player moves the player in a given direction if the player is able to.
// if the player moves into an open exit, they win the game.
// it returns (1) if the player moved, and (0) if they did not.
int	move_player(int key, char **map, int x, int y)
{
	if (key == 119)
	{
		map[y][x] = 'P';
		if (map[y - 1][x] == 'E')
			game_win();
		else if (map[y - 1][x] != '1' && map[y - 1][x] != 'e')
		{
			map[y][x] = 'o';
			map[y - 1][x] = 'P';
			return (1);
		}
	}
	else if (key == 97)
	{
		map[y][x] = 'A';
		if (map[y][x - 1] == 'E')
			game_win();
		else if (map[y][x - 1] != '1' && map[y][x - 1] != 'e')
		{
			map[y][x] = 'o';
			map[y][x - 1] = 'A';
			return (1);
		}
	}
	return (move_player2(key, map, x, y));
}
