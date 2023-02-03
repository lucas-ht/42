/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:29:21 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 04:37:01 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

/*
* Converts the linked list to an array.
*/

static void	ft_spots_to_map(t_map *map, t_spot *spots)
{
	int		i;
	t_spot	*spot;

	map->z = (int *) ft_calloc(map->width * map->height, sizeof(int));
	map->color = (uint32_t *) ft_calloc(map->width * map->height,
			sizeof(uint32_t));
	map->projection = (t_point *) ft_calloc(map->width * map->height,
			sizeof(t_point));
	if (!map->z || !map->color || !map->projection)
		ft_error(ERROR_MALLOC);
	i = 0;
	spot = spots;
	while (spot)
	{
		map->z[i] = spot->z;
		map->color[i] = spot->color;
		i++;
		spot = spot->next;
		free(spots);
		spots = spot;
	}
}

/*
* Parses one spot.
*/

static void	ft_parse_next(t_spot **spots, char *s)
{
	t_spot	*spot;
	char	**data;

	spot = (t_spot *) ft_calloc(1, sizeof(t_spot));
	if (!spot)
		ft_error(ERROR_MALLOC);
	data = ft_split(s, ',');
	if (!data || !ft_striter_if(data[0], ft_isdigit))
		ft_error(ERROR_PARSE);
	if (data[1] && !ft_striter_if(data[1], ft_ishex))
		ft_error(ERROR_PARSE);
	spot->z = ft_atoi(data[0]);
	if (data[1])
		spot->color = ft_atoi_hex(data[1]);
	else
		spot->color = COLOR_UNSPECIFIED;
	ft_free_split(data);
	spot->next = *spots;
	*spots = spot;
}

/*
* Reads and splits the map.
*/

static t_spot	*ft_parse_map(t_map *map, int fd)
{
	t_spot	*spots;
	char	*line;
	char	**s;
	int		x;
	int		y;

	spots = 0;
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		s = ft_split(line, ' ');
		x = -1;
		while (s[++x])
			ft_parse_next(&spots, s[x]);
		map->width = t(!map->width, x, map->width);
		if (map->width != x)
			ft_error(ERROR_PARSE_RECT);
		ft_free_split(s);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	map->height = y;
	return (spots);
}

/*
* Entrypoint to the parsing, also checks the validity of the arguments.
*/

t_map	*ft_parse(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_spot	*spots;

	if (ac != 2)
		ft_error(ERROR_PARSE_ARGS);
	if (!ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))
		ft_error(ERROR_PARSE_NAME);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_PARSE_OPEN);
	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_error(ERROR_MALLOC);
	map->width = 0;
	map->height = 0;
	spots = ft_parse_map(map, fd);
	if (map->width < 2 || map->height < 2)
		ft_error(ERROR_PARSE_SIZE);
	ft_spots_to_map(map, spots);
	return (map);
}
