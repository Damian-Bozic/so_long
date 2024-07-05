/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:25:55 by dbozic            #+#    #+#             */
/*   Updated: 2024/07/03 17:25:57 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	draw_frame(char **map, t_game *root, int count)
{
	int		x;
	int		y;
	char	*str;

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
	str = ft_itoa(count);
	if (!str)
		clean_exit(-1, &root);
	mlx_string_put(root->mlx, root->win, 8, 24, 2147483647, str);
	free(str);
}
