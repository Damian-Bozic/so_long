/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:50:00 by dbozic            #+#    #+#             */
/*   Updated: 2024/06/27 14:50:02 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_is_completable(char **map)
{
	if (count_tiles('P', map) != 1)
	{
		ft_printf("Error\nmap has an ivalid amount of players\n");
		ft_printf("%d\n", count_tiles('P', map));
		return (0);
	}
	if (count_tiles('E', map) != 1)
	{
		ft_printf("Error\nmap has an invalid amount of exits\n");
		return (0);
	}
	if (count_tiles('C', map) == 0)
	{
		ft_printf("Error\nmap has no collectables\n");
		return (0);
	}
	if (!flood_map(map))
		return (0);
	return (1);
}

// check_map_boarder checks if the boarder of the map is made of walls ('1's)
static int	check_map_boarder(int size_x, int size_y, char **map)
{
	int	i;

	i = 0;
	if (size_x > 60 || size_y > 32)
		return (ft_printf("Error\nMap is too big\n"));
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][size_x - 1] != '1')
			return (ft_printf("Error\nMap is not surrounded\n"));
		i++;
	}
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[size_y - 1][i] != '1')
			return (ft_printf("Error\nMap is not surrounded\n"));
		i++;
	}
	return (1);
}

static int check_map_format(int xsize, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if ((map[y][x] != '1') && (map[y][x] != '0') && (map[y][x] != 'C')
				&& (map[y][x] != 'P') && (map[y][x] != 'E'))
			{
				ft_printf("Error\ninvalid symbol in map file: %c\n", map[y][x]);
				return (0);
			}
			x++;
		}
		if (x != xsize)
			ft_printf("Error\nmap is not rectangular\n");
		if (x != xsize)
			return (0);
		x = 0;
		y++;
	}
	return (1);
}

// check_map checks if the map complies with the following rules:
// -map is not square
// -map is surrounded by walls
// -map only has one player
// -map only has one exit
// -map has at least one collectable
// -map is possible to complete
int	check_map(char **map, t_game **game)
{
	int	x;
	int	y;
	t_game	*root;

	root = *game;
	while (map[root->my])
		root->my++;
	while (map[0][root->mx] != '\n' && (map[0][root->mx]))
		root->mx++;
	x = root->mx;
	y = root->my;
	if ((!check_map_format(x, map)) || (check_map_boarder(x, y, map) != 1)
		|| (!map_is_completable(map)))
	{
		free_map(map);
		return (0);
	}
	if (x == y)
	{
		ft_printf("Error\nMap is square\n");
		free_map(map);
		return (0);
	}
	return (1);
}

int check_file_type(char *file_name)
{
	int	i;

	i = ft_strlen(file_name);
	if (i < 4)
	{
		ft_printf("Error\ninvalid file\n");
		clean_exit(-1, NULL);
	}
	i = i - 4;
	if (ft_strncmp(&file_name[i], ".ber", 4) != 0)
	{
		ft_printf("Error\ninvalid file\n");
		clean_exit(-1, NULL);
	}
	return (1);
}