/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:07:51 by troudot           #+#    #+#             */
/*   Updated: 2023/04/16 04:38:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_map_reader(int fd)
{
	char	*buf;
	char	*line;
	char	**result;

	line = 0;
	buf = get_next_line(fd);
	if (!buf)
		ft_error(ERROR_PARSING);
	while (buf)
	{
		line = ft_strjoin_free(line, buf);
		if (!line)
			ft_error(ERROR_PARSING);
		line = ft_strjoin_free(line, "\n");
		if (!line)
			ft_error(ERROR_PARSING);
		free(buf);
		buf = get_next_line(fd);
	}
	result = ft_split(line, "\n");
	if (!result)
		ft_error(ERROR_PARSING);
	return (free(line), result);
}

static int	ft_parse_file(char *av)
{
	int		fd;

	if (ft_strcmp(&av[ft_strlen(av) - 4], ".cub"))
		ft_error(ERROR_MAP_EXTENSION);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_PARSING_FILE);
	return (fd);
}

/**
 * It takes a file name as an argument, opens it, reads it, and parses it
 * 
 * @param av the name of the file to be parsed
 * 
 * @return A pointer to a t_arg struct.
 */
t_map	*ft_parsing(t_player *player, char *av)
{
	t_map	*map;
	int		fd;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_error(ERROR_PARSING);
	fd = ft_parse_file(av);
	map->map_raw = ft_map_reader(fd);
	if (!map->map_raw)
		ft_error(ERROR_PARSING);
	if (close(fd) == -1)
		ft_error(ERROR_PARSING_FILE);
	map->textures = ft_calloc(1, sizeof(t_textures));
	if (!map->textures)
		ft_error(ERROR_PARSING);
	ft_parse_texture(map);
	ft_fill_empty_case(map->map_raw);
	map->width = ft_split_longest(map->map_raw);
	map->height = ft_split_len(map->map_raw);
	ft_check_map(map);
	ft_parse_player(map->map_raw, player);
	map->map = ft_char_to_elem(map->map_raw);
	return (map);
}
