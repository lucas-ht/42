/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:30:52 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 01:12:36 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_minimap_renderer(t_cub3d *cub, t_vector3 pos, uint32_t color)
{
	int		x;
	int		y;

	x = -1;
	while (++x < cub->map->minimap)
	{
		y = -1;
		while (++y < cub->map->minimap)
			mlx_put_pixel(cub->mlx->minimap_player,
				pos.x + x, pos.y + y, color);
	}
}

static void	ft_minimap_render_ray(t_cub3d *cub, int angle)
{
	t_vector3	trace;
	int			distance;
	t_elem		elem;

	distance = -1;
	while (++distance < MINIMAP_RAY_DISTANCE)
	{
		trace = cub->player->angle;
		trace.y += angle * PLAYER_FOV / MINIMAP_RAY_NUMBER;
		trace = ft_euler_normalize(trace);
		trace = ft_angle_polar(trace, distance * 10);
		trace = ft_vector3_add(trace, cub->player->pos);
		elem = ft_map_at(cub, trace.x, trace.y);
		if (elem == M_WALL || elem == M_DOOR)
			break ;
		trace.x = trace.x * cub->map->minimap / MAP_MULTIPIER;
		trace.y = trace.y * cub->map->minimap / MAP_MULTIPIER;
		ft_minimap_renderer(cub, trace, 0xFFFFFFC8
			- distance * 200 / MINIMAP_RAY_DISTANCE);
	}
}

static void	ft_minimap_render_fov(t_cub3d *cub)
{
	int			angle;

	angle = -1;
	while (++angle < MINIMAP_RAY_NUMBER)
		ft_minimap_render_ray(cub, angle);
}

void	ft_minimap_render_player(t_cub3d *cub)
{
	t_vector3	pos;

	if (!MINIMAP_RENDER)
		return ;
	ft_mlx_clear(cub->mlx->minimap_player);
	pos.x = (cub->player->pos.x + cub->map->minimap / 2)
		* cub->map->minimap / MAP_MULTIPIER;
	pos.y = cub->player->pos.y * cub->map->minimap / MAP_MULTIPIER;
	ft_minimap_render_fov(cub);
	ft_minimap_renderer(cub, pos, 0xC80000FF);
}
