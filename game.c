/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:54:58 by sasano            #+#    #+#             */
/*   Updated: 2023/11/29 02:39:15 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	put_element(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1')
		put_image(game, '1', x, y);
	else if (map[y][x] == 'P')
	{
		put_image(game, 'P', x, y);
		game->player.x = x;
		game->player.y = y;
	}
	else if (map[y][x] == 'C')
	{
		put_image(game, 'C', x, y);
		game->map.total_coin++;
	}
	else if (map[y][x] == 'E')
		put_image(game, 'E', x, y);
}

static void	put_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			put_element(game, map, x, y);
	}
}

static int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	else
		key_press_player(key_code, game);
	return (0);
}

void	loop_game(t_game *game, int map_width, int map_height)
{
	put_map(game, game->map.map_str);
	if (check_playable(*game, map_width, map_height))
		img_error("Error\nMap is not playable\n", game);
	mlx_hook(game->win, 17, 1L << 2, destroy_window, (void *)game);
	mlx_key_hook(game->win, key_check, (void *)game);
	mlx_loop(game->mlx);
}
