/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:30:58 by dbozic            #+#    #+#             */
/*   Updated: 2024/07/08 14:31:10 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// free_game_struct frees the struct and the linked list within it.
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

// clean_exit frees everything in use in **game, then closes the program.
// it can also print an error message depending on the error code given.
void	clean_exit(int code, t_game **game)
{
	t_list	*asset;
	t_game	*root;

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
