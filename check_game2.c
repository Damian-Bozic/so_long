/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_helper_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:50:10 by dbozic            #+#    #+#             */
/*   Updated: 2024/06/27 14:50:12 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns how many tiles are of a given char
int	count_tiles(char c, char **map)
{
	int	xpos;
	int	ypos;
	int	flag;

	xpos = 0;
	ypos = 0;
	flag = 0;
	while (map[ypos])
	{
		while (map[ypos][xpos])
		{
			if (map[ypos][xpos] == c)
				flag++;
			xpos++;
		}
		xpos = 0;
		ypos++;
	}
	return (flag);
}

// checks if a given tile is "flooded"
static int	is_flooded(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return (0);
	if (c == 'P' || c == 'o' || c == 'c')
		return (1);
	return (2);
}

// checks whether the given tile position is already flooded.
// if it isnt flooded, and if one of its nieghbors are flooded
//  the tile given becomes "flooded"
static int	check_nieghbors(int x, int y, char **map)
{
	if (is_flooded(map[y][x]) == 0)
	{
		if (is_flooded(map[y - 1][x]) == 1 || is_flooded(map[y + 1][x]) == 1
			|| is_flooded(map[y][x - 1]) == 1 || is_flooded(map[y][x + 1]) == 1)
		{
			if (map[y][x] == '0')
				map[y][x] = 'o';
			else if (map[y][x] == 'C')
				map[y][x] = 'c';
			else if (map[y][x] == 'E')
				map[y][x] = 'e';
			return (1);
		}
		return (0);
	}
	return (0);
}

static int	flood_map_cycle(char **map)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (check_nieghbors(x, y, map))
				flag++;
			x++;
		}
		x = 0;
		y++;
	}
	return (flag);
}

// flood_map checks if the player is able to reach all collectables and
//  the exit by finding all possible squares the player can reach.
// it does this by "flooding" all the reachable parts of the map.
// if by the end a critical tile remains "unflooded", it means that the map
//  is incompletable.
//
// 11111 	11111 	 11111 	  11111    11111
// 1C0E1 	1C0E1	 1c0E1 	  1coE1    1coe1
// 10001 -> 1o001 -> 1oo01 -> 1ooo1 -> 1ooo1
// 1P001 	1Po01 	 1poo1 	  1poo1    1poo1
// 11111 	11111 	 11111 	  11111    11111
//
// if no tiles are transformed in a cycle then the map is fully "flooded"
//  and can be checked for any "unflooded" tiles.
int	flood_map(char **map)
{
	int	cycles;

	cycles = 0;
	while (flood_map_cycle(map))
		cycles++;
	if (count_tiles('E', map) || (count_tiles('C', map)))
	{
		ft_printf("Error\nNot all critical tiles are accessable\n");
		return (0);
	}
	return (1);
}
