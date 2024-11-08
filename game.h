/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:53:44 by sasano            #+#    #+#             */
/*   Updated: 2023/11/29 02:40:34 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysymdef.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define ESC 65307
#define LEFT 65361
#define UP 65362
#define RIGHT 65363
#define DOWN 65364
#define DEF_SIZE 32

typedef struct s_map
{
	int			total_coin;
	void		*wall_img;
	void		*back_img;
	void		*coin_img;
	void		*goal_img;
	char		**map_str;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			coin_count;
	int			move_count;
	void		*player_img;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
}				t_game;

char			**check_input_map(int argc, char *argv[], int *map_width,
					int *map_height);
int				check_playable(t_game game, int map_width, int map_height);
void			loop_game(t_game *game, int map_width, int map_height);
int				key_press_player(int keycode, t_game *game);
void			put_image(t_game *game, char tag, int x, int y);
void			check_coin(t_game *game);
// void			end_game(t_game *game);
void			free_map(char **map);
void			free_images(t_game *game);
int				destroy_window(t_game *game);
void			map_error(char *str, char **map);
void			img_error(char *str, t_game *game);