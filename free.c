/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 00:02:19 by sasano            #+#    #+#             */
/*   Updated: 2023/11/29 02:43:35 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_images(t_game *game)
{
	if (game->map.back_img)
		mlx_destroy_image(game->mlx, game->map.back_img);
	if (game->map.wall_img)
		mlx_destroy_image(game->mlx, game->map.wall_img);
	if (game->map.coin_img)
		mlx_destroy_image(game->mlx, game->map.coin_img);
	if (game->map.goal_img)
		mlx_destroy_image(game->mlx, game->map.goal_img);
	if (game->player.player_img)
		mlx_destroy_image(game->mlx, game->player.player_img);
}
