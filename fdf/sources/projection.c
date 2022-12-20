/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:32:41 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 08:04:17 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
* Rotates the projection.
*/

static void	ft_project_rotate(t_point *point, t_euler angle)
{
	t_point	p;

	p = ft_point_copy(point);
	point->x = p.x * cos(angle.y) * cos(angle.z)
		+ p.z * sin(angle.y) - p.y * sin(angle.z);
	point->y = p.y * cos(angle.x) * cos(angle.z)
		+ p.z * sin(angle.x) + p.x * sin(angle.z);
	point->z = p.z * cos(angle.x) * cos(angle.y)
		+ p.x * sin(angle.y) - p.y * sin(angle.x);
}

/*
* Converts the projection to an isometric one,
* using pre calculated values of cos(30°) and sin(30°).
*/

static void	ft_project_isometric(t_point *point)
{
	t_point	p;

	p = ft_point_copy(point);
	point->x = (p.x - p.y) * 0.86;
	point->y = -p.z + (p.x + p.y) * 0.5;
}

/*
* Projects the coordinate.
*/

t_point	ft_project(t_fdf *fdf, t_point point)
{
	ft_point_set(&point, point.x * fdf->camera->zoom, point.y
		* fdf->camera->zoom, point.z * fdf->camera->zoom / fdf->camera->z);
	point.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	point.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	ft_project_rotate(&point, fdf->camera->angle);
	if (fdf->camera->projection == PROJECTION_ISOMETRIC)
		ft_project_isometric(&point);
	point.x += MLX_WIDTH / 2 + fdf->camera->position.x;
	point.y += (MLX_HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
		+ fdf->camera->position.y;
	point.z = 0;
	return (point);
}

/*
* Draws a line between 2 points using Bresenham's Line Algorithm.
*		p[0] is the delta between the two points.
*		p[1] stores the sign of depending of the greater value.
*		p[2] is the iterative value.
*		e stores the errors, to avoid infinite loops.
*/

void	ft_draw_line(t_fdf *fdf, t_point point1, t_point point2)
{
	t_point	p[3];
	int		e[2];

	ft_point_set(&p[0], abs(point2.x - point1.x), abs(point2.y - point1.y), 0);
	ft_point_set(&p[1], t(point1.x < point2.x, 1, -1),
		t(point1.y < point2.y, 1, -1), 0);
	p[2] = ft_point_copy(&point1);
	e[0] = p[0].x - p[0].y;
	while (p[2].x != point2.x || p[2].y != point2.y)
	{
		ft_draw_pixel(fdf, p[2]);
		e[1] = e[0] * 2;
		if (e[1] > -p[0].y)
		{
			e[0] -= p[0].y;
			p[2].x += p[1].x;
		}
		if (e[1] < p[0].x)
		{
			e[0] += p[0].x;
			p[2].y += p[1].y;
		}
	}
}
