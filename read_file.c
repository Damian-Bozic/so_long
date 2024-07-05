/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:59:55 by dbozic            #+#    #+#             */
/*   Updated: 2024/06/27 15:00:01 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
// array of strings.
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

// free_map frees every str in the map array, then frees the array itself.
void	free_map(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	check_file_type(char *file_name)
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
