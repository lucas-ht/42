/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:26:49 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 01:18:13 by lucas            ###   ########.fr       */
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
			mlx_put_pixel(cub->mlx->minimap, pos.x + x + cub->map->minimap / 2,
				pos.y + y + cub->map->minimap / 2, color);
	}
}

void	ft_minimap_render(t_cub3d *cub)
{
	t_vector3	pos;
	uint32_t	color;

	if (!MINIMAP_RENDER)
		return ;
	ft_mlx_clear(cub->mlx->minimap);
	pos.y = -1;
	while (++pos.y < cub->map->height)
	{
		pos.x = -1;
		while (++pos.x < cub->map->width)
		{
			color = 0;
			if (cub->map->map[pos.y][pos.x] == M_WALL)
				color = 0x00000050;
			if (cub->map->map[pos.y][pos.x] == M_DOOR)
				color = cub->map->color_floor & 0xC8C8C850;
			if (cub->map->map[pos.y][pos.x] == M_FLOOR)
				color = cub->map->color_floor & 0xFFFFFF80;
			ft_minimap_renderer(cub,
				ft_vector3_multiply(pos, cub->map->minimap), color);
		}
	}
}
