/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:25 by sasano            #+#    #+#             */
/*   Updated: 2024/02/07 23:10:32 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_coin(t_game *game)
{
	if (game->map.map_str[game->player.y][game->player.x] == 'C')
	{
		game->map.map_str[game->player.y][game->player.x] = '0';
		game->player.coin_count++;
	}
}

void	put_image(t_game *game, char tag, int x, int y)
{
	void	*img;

	if (tag == '1')
		img = game->map.wall_img;
	else if (tag == 'P')
		img = game->player.player_img;
	else if (tag == 'C')
		img = game->map.coin_img;
	else if (tag == '0')
		img = game->map.back_img;
	else
		img = game->map.goal_img;
	mlx_put_image_to_window(game->mlx, game->win, img, x * DEF_SIZE, y
		* DEF_SIZE);
}

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_images(game);
	exit(0);
}
