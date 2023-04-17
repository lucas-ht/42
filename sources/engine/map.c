/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:24:25 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:27:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_elem	ft_map_at(t_cub3d *cub, double x, double y)
{
	if (x <= 0 || x / MAP_MULTIPIER >= cub->map->width)
		return (M_WALL);
	if (y <= 0 || y / MAP_MULTIPIER >= cub->map->height)
		return (M_WALL);
	return (cub->map->map[(int) y / MAP_MULTIPIER][(int) x / MAP_MULTIPIER]);
}

static void	ft_map_open(t_cub3d *cub, t_vector3 pos)
{
	double		dist;
	t_elem		elem;

	elem = cub->map->map[pos.y][pos.x];
	if (elem != M_DOOR && elem != M_DOOR_OPEN)
		return ;
	dist = ft_vector3_dist(ft_vector3_multiply(pos, MAP_MULTIPIER),
			cub->player->pos, sqrt);
	if (dist > MAP_DOOR_OPEN * MAP_MULTIPIER
		|| dist < MAP_DOOR_CLOSE * MAP_MULTIPIER)
		return ;
	if (cub->map->map[pos.y][pos.x] == M_DOOR)
		cub->map->map[pos.y][pos.x] = M_DOOR_OPEN;
	else if (cub->map->map[pos.y][pos.x] == M_DOOR_OPEN)
		cub->map->map[pos.y][pos.x] = M_DOOR;
}

void	ft_map_door_open(t_cub3d *cub)
{
	int		x;
	int		y;

	y = -1;
	while (++y < cub->map->height)
	{
		x = -1;
		while (++x < cub->map->width)
			ft_map_open(cub, ft_vector3_new(x, y, 0));
	}
}
