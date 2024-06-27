/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:42:49 by dbozic            #+#    #+#             */
/*   Updated: 2024/06/27 17:43:05 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *make_game_struct(void)
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
	game->mx = 0;
	game->my = 0;
	return (game);
}

static void	free_game_struct(t_game **game)
{
	t_game	*root;
	t_list	*current;
	t_list	*next;

	if (!game)
		return ;
	root = *game;
	if (root->map)
		free_map(root->map);
	if (root->mlx)
	{
		mlx_destroy_display(root->mlx);
		free(root->mlx);
	}
	current = root->sprites;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	root->sprites = NULL;
	free(*game);
	*game = NULL;
}

void	clean_exit(int code, t_game **game)
{
	t_list *asset;
	t_game *root;

	if (!game)
		exit(code);
	root = *game;
	asset = root->sprites;
	if (code == 1)
		ft_printf("Error\nfailed to initialise mlx\n");
	else if (code == 2)
		ft_printf("Error\nfailed to open new window\n");
	else if (code == 3)
		ft_printf("Error\nfailed to load an image\n");
	else if (code == 4)
		ft_printf("Error\nInvalid Parameters\n");
	while (asset)
	{
		mlx_destroy_image(root->mlx, asset->content);
		asset = asset->next;
	}
	if (root->win)
		mlx_destroy_window(root->mlx, root->win);
	free_game_struct(game);
	exit(code);
}
