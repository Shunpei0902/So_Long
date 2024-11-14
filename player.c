/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:34:50 by sasano            #+#    #+#             */
/*   Updated: 2024/11/14 16:56:45 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	end_game(t_game *game)
{
	ft_printf("TOTAL MOVES: %d\n", game->player.move_count);
	destroy_window(game);
}

static void	put_update(t_game *game, int pre_x, int pre_y)
{
	char	**map;

	map = game->map.map_str;
	if (map[pre_y][pre_x] == 'E')
		put_image(game, 'E', pre_x, pre_y);
	else
		put_image(game, '0', pre_x, pre_y);
	put_image(game, 'P', game->player.x, game->player.y);
	if (map[game->player.y][game->player.x] == 'E'
		&& game->player.coin_count == game->map.total_coin)
	{
		ft_printf("You win!\n");
		end_game(game);
	}
}

static void	check_move(t_game *game, int *move)
{
	int		i;
	int		x;
	int		y;
	char	**map;

	i = -1;
	while (++i < 4)
		move[i] = 1;
	x = game->player.x;
	y = game->player.y;
	map = game->map.map_str;
	if (map[y - 1][x] == '1')
		move[0] = 0;
	if (map[y][x + 1] == '1')
		move[1] = 0;
	if (map[y + 1][x] == '1')
		move[2] = 0;
	if (map[y][x - 1] == '1')
		move[3] = 0;
}

static int	move_player(int key_code, t_game *game, int *move)
{
	if (key_code == UP && move[0] == 1)
		game->player.y -= 1;
	else if (key_code == RIGHT && move[1] == 1)
		game->player.x += 1;
	else if (key_code == DOWN && move[2] == 1)
		game->player.y += 1;
	else if (key_code == LEFT && move[3] == 1)
		game->player.x -= 1;
	else
		return (0);
	return (1);
}

int	key_press_player(int key_code, t_game *game)
{
	int	pre_x;
	int	pre_y;
	int	move[4];

	pre_x = game->player.x;
	pre_y = game->player.y;
	check_move(game, move);
	if (move_player(key_code, game, move))
	{
		check_coin(game);
		put_update(game, pre_x, pre_y);
		game->player.move_count++;
		ft_printf("move_count: %d     coin_count: %d\n",
			game->player.move_count, game->player.coin_count);
	}
	return (0);
}
