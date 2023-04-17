/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 07:55:14 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 02:48:58 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_background(t_cub3d *cub)
{
	int			x;
	int			y;
	uint32_t	color;

	if (cub->map->textures->sky)
	{
		cub->mlx->background_sky = ft_mlx_texture_image(cub->mlx->mlx,
				cub->map->textures->sky, (t_vector3){0, 0, 0, 0});
		mlx_set_instance_depth(cub->mlx->background_sky->instances, 0);
	}
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			color = cub->map->color_floor;
			if (y < HEIGHT / 2)
				color = t(!!cub->map->textures->sky, 0x00000000,
						cub->map->color_ceiling);
			mlx_put_pixel(cub->mlx->background, x, y, color);
		}
	}
}
