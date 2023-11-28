/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:26:54 by sasano            #+#    #+#             */
/*   Updated: 2023/11/27 01:43:27 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	map_error(char *str, char **map)
{
	printf("%s", str);
	free_map(map);
	exit(0);
}

void	img_error(char *str, t_game *game)
{
	printf("%s", str);
	free_images(game);
	exit(0);
}
