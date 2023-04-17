/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 04:12:42 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 04:33:24 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_parse_textures(t_textures *textures, char *ar)
{
	if (!ft_strncmp(ar, "NO ", 3))
		textures->north = ft_mlx_texture_png(&ar[3]);
	if (!ft_strncmp(ar, "SO ", 3))
		textures->south = ft_mlx_texture_png(&ar[3]);
	if (!ft_strncmp(ar, "WE ", 3))
		textures->west = ft_mlx_texture_png(&ar[3]);
	if (!ft_strncmp(ar, "EA ", 3))
		textures->east = ft_mlx_texture_png(&ar[3]);
	if (!ft_strncmp(ar, "DO ", 3))
		textures->door = ft_mlx_texture_png(&ar[3]);
	if (!ft_strncmp(ar, "SK ", 3))
		textures->sky = ft_mlx_texture_png(&ar[3]);
}

static void	ft_parse_colors(t_map *map, char *ar)
{
	char		**data;
	uint8_t		color[3];

	if (ft_strncmp(ar, "F ", 2) && ft_strncmp(ar, "C ", 2))
		return ;
	data = ft_split(&ar[2], ",");
	color[0] = ft_atoi(data[0]);
	color[1] = ft_atoi(data[1]);
	color[2] = ft_atoi(data[2]);
	ft_free_split(data);
	if (!ft_strncmp(ar, "F ", 2))
		map->color_floor = ft_mlx_color(color[0], color[1], color[2]);
	if (!ft_strncmp(ar, "C ", 2))
		map->color_ceiling = ft_mlx_color(color[0], color[1], color[2]);
}

static bool	ft_is_texture(char *av)
{
	if (!ft_strncmp(av, "NO ", 3))
		return (true);
	if (!ft_strncmp(av, "SO ", 3))
		return (true);
	if (!ft_strncmp(av, "WE ", 3))
		return (true);
	if (!ft_strncmp(av, "EA ", 3))
		return (true);
	if (!ft_strncmp(av, "DO ", 3))
		return (true);
	if (!ft_strncmp(av, "SK ", 3))
		return (true);
	if (!ft_strncmp(av, "F ", 2))
		return (true);
	if (!ft_strncmp(av, "C ", 2))
		return (true);
	return (false);
}

/**
 * It parses the arguments
 * and stores them in the t_arg structure
 * 
 * @param arg a pointer to the t_arg structure
 * @param av the name of the file
 * 
 * @return the value of EXIT_SUCCESS.
 */
void	ft_parse_texture(t_map *map)
{
	int		i;

	i = -1;
	while (map->map_raw[++i])
	{
		if (!ft_is_texture(map->map_raw[i]))
			continue ;
		ft_parse_colors(map, map->map_raw[i]);
		ft_parse_textures(map->textures, map->map_raw[i]);
		map->map_raw = ft_split_pop(map->map_raw, i--);
		if (!map->map_raw)
			ft_error(ERROR_PARSING);
	}
	if (!ft_split_check_digit(map->map_raw))
		ft_error(ERROR_MAP);
}
