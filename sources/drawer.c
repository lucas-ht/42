/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:29:43 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 08:08:13 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
* Checks if the screen coordinate is on screen and
* write the color to memory.
*/

void	ft_draw_pixel(t_fdf *fdf, t_point point)
{
	int			i;

	if (!ft_point_inside(point))
		return ;
	point.color = t(point.color == COLOR_UNSPECIFIED, fdf->color, point.color);
	i = (point.x * fdf->mlx->bits_per_pixel / 8)
		+ (point.y * fdf->mlx->size_line);
	fdf->mlx->data_addr[i] = point.color;
	fdf->mlx->data_addr[++i] = point.color >> 8;
	fdf->mlx->data_addr[++i] = point.color >> 16;
}

/*
* Stores the projections and draws its lines.
*/

static void	ft_draw_map(t_fdf *fdf, t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			i = y * map->width + x;
			map->projection[i] = ft_project(fdf, ft_point_at(fdf->map, x, y));
			if (!ft_point_inside(map->projection[i]))
				continue ;
			if (x > 0)
				ft_draw_line(fdf, map->projection[i], map->projection[i - 1]);
			if (y > 0)
				ft_draw_line(fdf, map->projection[i],
					map->projection[i - map->width]);
		}
	}
}

/*
* Draws the menu.
*/

static void	ft_draw_menu(void *mlx, void *win)
{
	int	y;

	y = 0;
	mlx_string_put(mlx, win, 15, y += 10, COLOR_TEXT, "Zoom         : +/-");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Move         : WASD");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Z factor     : UP/DOWN");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Projection   : P");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Color        : C");
	mlx_string_put(mlx, win, 15, y += 30, COLOR_TEXT, "Rotate       : 4-6");
}

/*
* Handles the initial zoom and position of the camera.
*/

static void	ft_draw_init(t_fdf *fdf, t_map *map)
{
	int	i;

	if (!fdf->camera->init.z)
		return ;
	i = -1;
	while (++i < map->width * map->height)
	{
		fdf->camera->init.x = min(fdf->camera->init.x, map->projection[i].y);
		fdf->camera->init.y = max(fdf->camera->init.x, map->projection[i].y);
	}
	fdf->camera->position.y -= fdf->camera->init.x;
	fdf->camera->init.z = 0;
	ft_draw(fdf, map);
	return ;
}

/*
* Resets the map and calls the others.
*/

void	ft_draw(t_fdf *fdf, t_map *map)
{
	fdf->redraw = 0;
	ft_bzero(fdf->mlx->data_addr, MLX_SIZE * (fdf->mlx->bits_per_pixel / 8));
	ft_draw_map(fdf, fdf->map);
	ft_draw_init(fdf, map);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->mlx->img, 0, 0);
	ft_draw_menu(fdf->mlx->mlx, fdf->mlx->win);
}
