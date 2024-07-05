/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:30:47 by dbozic            #+#    #+#             */
/*   Updated: 2024/07/03 17:30:58 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player2(int key, char **map, int x, int y)
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
		}
	}
}

void	move_player(int key, char **map, int x, int y)
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
		}
	}
	else
		move_player2(key, map, x, y);
}

void	find_char_on_map(char **map, char *str, int *x, int *y)
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
