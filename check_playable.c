/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:41:35 by sasano            #+#    #+#             */
/*   Updated: 2023/11/29 01:29:44 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static char	**copy_map(char **map, int map_width, int map_height)
{
	int		x;
	int		y;
	char	**copy;

	y = -1;
	copy = (char **)malloc(sizeof(char *) * (map_height + 1));
	while (map[++y])
	{
		x = -1;
		copy[y] = (char *)malloc(sizeof(char) * map_width + 2);
		while (map[y][++x])
			copy[y][x] = map[y][x];
		copy[y][x] = '\0';
	}
	copy[y] = NULL;
	return (copy);
}

static void	recursion(char **map, int x, int y)
{
	if (map[y][x] != '1' && map[y][x] != 'X')
	{
		if (x == 0 || y == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
			map_error("Error\nMap is not closed\n", map);
		map[y][x] = 'X';
		recursion(map, x + 1, y);
		recursion(map, x - 1, y);
		recursion(map, x, y + 1);
		recursion(map, x, y - 1);
	}
}

int	check_playable(t_game game, int map_width, int map_height)
{
	int		x;
	int		y;
	char	**map;

	map = copy_map(game.map.map_str, map_width, map_height);
	recursion(map, game.player.x, game.player.y);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				return (1);
			else if (map[y][x] == 'E')
				return (1);
		}
	}
	free_map(map);
	return (0);
}
