/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:26:15 by dbozic            #+#    #+#             */
/*   Updated: 2024/07/08 14:26:26 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// load_sprites2 takes an array of file names then loads all the files into a 
//  a linked list. it also frees the array of file names.
static void	load_sprites2(t_game *root, char **assets)
{
	t_list	*current;
	int		i;
	int		x;

	i = 0;
	current = root->sprites;
	while (assets[i])
	{
		current = ft_lstnew(mlx_xpm_file_to_image(root->mlx, assets[i], &x,
					&x));
		if (!current)
		{
			free(assets);
			clean_exit(3, &root);
		}
		if (!root->sprites)
			root->sprites = current;
		else
			ft_lstadd_back(&root->sprites, current);
		i++;
	}
	free(assets);
}

// load_sprites allocates an array of file names
void	load_sprites(t_game *root)
{
	char	**assets;

	assets = malloc(sizeof(char *) * 11);
	if (!assets)
		clean_exit(-1, &root);
	assets[0] = "sprites/background.xpm";
	assets[1] = "sprites/wall.xpm";
	assets[2] = "sprites/collect.xpm";
	assets[3] = "sprites/exit.xpm";
	assets[4] = "sprites/playerw.xpm";
	assets[5] = "sprites/playera.xpm";
	assets[6] = "sprites/players.xpm";
	assets[7] = "sprites/playerd.xpm";
	assets[8] = "sprites/exit_open.xpm";
	assets[9] = "sprites/footprint.xpm";
	assets[10] = NULL;
	load_sprites2(root, assets);
}

// make_game_struct initializes and allocates the game struct.
t_game	*make_game_struct(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->win = NULL;
	game->sprites = NULL;
	game->map = NULL;
	game->status = 0;
	game->moves = 0;
	game->mx = 0;
	game->my = 0;
	return (game);
}

// file_line_count checks how many lines are in a given file descriptor.
static int	file_line_count(char *address)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(address, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\ninvalid File\n");
		return (-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
	return (i);
}

// create_map makes takes in the map file and creates a replica as an
//  array of strings.
char	**create_map(char *address, t_game **game)
{
	char	**map;
	int		fd;
	int		i;

	i = file_line_count(address);
	if (i == -1)
		clean_exit(-1, game);
	map = malloc((i + 1) * sizeof(char *));
	if (!map)
		clean_exit(-1, game);
	i = 0;
	fd = open(address, O_RDONLY);
	while (i == 0 || (map[i - 1]))
	{
		map[i] = get_next_line(fd);
		if (map[i])
			map[i][ft_strclen(map[i], '\n')] = '\0';
		i++;
	}
	close(fd);
	if (!check_map(map, game))
		clean_exit(-1, game);
	return (map);
}
