/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:48:52 by dbozic            #+#    #+#             */
/*   Updated: 2024/06/19 15:48:57 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_game
{
	t_xvar			*mlx;
	t_win_list		*win;
	struct s_list	*sprites;
	char			**map;
	int				mx;
	int				my;
	int				status;
	int				moves;
}	t_game;

//main
void	game_win(void);

//check_game
int		check_file_type(char *file_name);
int		check_map(char **map, t_game **game);
int		count_tiles(char c, char **map);
int		flood_map(char **map);

//setup_game
char	**create_map(char *address, t_game **game);
t_game	*make_game_struct(void);
void	load_sprites(t_game *root);

//draw_game
int		move_player(int key, char **map, int x, int y);
void	draw_frame(t_game *root, int count, int status, int y);

//close_game
void	free_map(char **ptr);
void	clean_exit(int code, t_game **game);

#endif