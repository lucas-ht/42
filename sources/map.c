/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:38:29 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 08:06:56 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point_set(t_point *self, int x, int y, int z)
{
	self->x = x;
	self->y = y;
	self->z = z;
}

t_point	ft_point_at(t_map *map, int x, int y)
{
	t_point	point;

	ft_point_set(&point, x, y, map->z[y * map->width + x]);
	point.color = map->color[y * map->width + x];
	return (point);
}

t_point	ft_point_copy(t_point *point)
{
	t_point	p;

	ft_point_set(&p, point->x, point->y, point->z);
	p.color = point->color;
	return (p);
}

int	ft_point_inside(t_point p)
{
	return (p.x >= 0 && p.x < MLX_WIDTH && p.y >= 0 && p.y < MLX_HEIGHT);
}
