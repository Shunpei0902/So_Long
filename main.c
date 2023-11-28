/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:01:56 by sasano            #+#    #+#             */
/*   Updated: 2023/11/29 02:39:31 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	init_map(t_game *game, char **map)
{
	int	size;

	size = DEF_SIZE;
	game->map.total_coin = 0;
	game->map.map_str = map;
	game->map.wall_img = mlx_xpm_file_to_image(game->mlx, "./img/map_block.xpm",
			&size, &size);
	game->map.back_img = mlx_xpm_file_to_image(game->mlx, "./img/back.xpm",
			&size, &size);
	game->map.coin_img = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm",
			&size, &size);
	game->map.goal_img = mlx_xpm_file_to_image(game->mlx, "./img/goal.xpm",
			&size, &size);
	game->player.player_img = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &size, &size);
	if (!game->map.coin_img || !game->map.back_img || !game->map.wall_img
		|| !game->map.map_str || !game->player.player_img
		|| !game->map.goal_img)
		img_error("Error\nImage error\n", game);
}

static void	init_game(char **map, int map_width, int map_height)
{
	t_game	game;

	game.mlx = mlx_init();
	init_map(&game, map);
	game.win = mlx_new_window(game.mlx, map_width * DEF_SIZE, map_height
			* DEF_SIZE, "Hello world!");
	game.player.coin_count = 0;
	game.player.move_count = 0;
	loop_game(&game, map_width, map_height);
}

int	main(int argc, char **argv)
{
	int		map_width;
	int		map_height;
	char	**map;

	map = check_input_map(argc, argv, &map_width, &map_height);
	init_game(map, map_width, map_height);
	return (0);
}
