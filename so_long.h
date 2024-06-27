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
}		t_game;


int 	check_file_type(char *file_name);
void	free_map(char **ptr);
char	**create_map(char *address, t_game **game);
int		count_tiles(char c, char **map);
int		check_map(char **map, t_game **game);
int		flood_map(char **map);
int		detect_close();
void	clean_exit(int code, t_game **game);
t_game *make_game_struct(void);

#endif