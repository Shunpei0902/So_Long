/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasano <shunkotkg0141@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:02:21 by sasano            #+#    #+#             */
/*   Updated: 2024/03/02 00:51:18 by sasano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static char	**ft_add_str_to_array(char **map, char *line)
{
	int		i;
	char	**new_map;

	i = 1;
	while (map && map[i])
		i++;
	new_map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_map)
	{
		free_map(map);
		map_error("Error\nMalloc error\n", NULL);
	}
	i = 0;
	while (map && map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	i = 0;
	free_map(map);
	return (new_map);
}

static void	check_element(char **map, int *check_array, int *map_width,
		int *map_height)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != '\n')
				map_error("Error\nMap with illegal characters\n", map);
			if (map[y][x] == 'P')
				check_array[0]++;
			if (map[y][x] == 'E')
				check_array[1]++;
			if (map[y][x] == 'C')
				check_array[2]++;
		}
	}
	if (map[y - 1][x - 1] == '\n')
		*map_width = x - 1;
	else
		*map_width = x;
	*map_height = y;
}

static char	**check_format_map(char **map, int *map_width, int *map_height)
{
	int	x;
	int	check_array[3];

	x = 0;
	while (x < 3)
		check_array[x++] = 0;
	check_element(map, check_array, map_width, map_height);
	if (check_array[0] != 1 || check_array[1] != 1 || check_array[2] == 0)
		map_error("Error\nInvalid map\n", map);
	return (map);
}

static char	**read_map(int fd, int *map_width, int *map_height)
{
	size_t	line_len;
	char	**map;
	char	*line;

	map = NULL;
	line_len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && map)
			return (check_format_map(map, map_width, map_height));
		else if (!line)
			map_error("Error\nempty map or get_next_line error\n", NULL);
		if (line_len != 0 && line_len != ft_strlen(line) && line[0] != '\0'
			&& line[0] != '\n' && (line_len == ft_strlen(line) - 1
				&& line[line_len - 1] != '\0'))
			map_error("Error\nMap is not rectangular\n", map);
		if (line[0] != '\0' && line[0] != '\n')
		{
			map = ft_add_str_to_array(map, line);
			line_len = ft_strlen(line);
		}
		free(line);
	}
}

char	**check_input_map(int argc, char *argv[], int *map_width,
		int *map_height)
{
	int	fd;

	if (argc != 2)
		map_error("Error\nInvalid argument\n", NULL);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		map_error("Error\nInvalid file type\n", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		map_error("Error\nInvalid file\n", NULL);
	return (read_map(fd, map_width, map_height));
}
