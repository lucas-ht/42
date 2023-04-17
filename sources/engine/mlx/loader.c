/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:42:41 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:55:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_loader(t_cub3d *cub)
{
	if (cub->loader == 1)
		return ;
	if (cub->loader < 0)
		return (cub->loader += 1, (void) 0);
	cub->map->minimap = min(MINIMAP_MAX, (min(MINIMAP_SIZE, min(WIDTH, HEIGHT))
				/ max(cub->map->width, cub->map->height)));
	ft_hud_init(cub);
	ft_weapon_init(cub);
	ft_render_background(cub);
	mlx_delete_image(cub->mlx->mlx, cub->mlx->intro);
	mlx_set_cursor_mode(cub->mlx->mlx, MLX_MOUSE_DISABLED);
	cub->mlx->mouse = 1;
	cub->loader = 1;
}
