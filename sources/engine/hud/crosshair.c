/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:00:23 by lucas             #+#    #+#             */
/*   Updated: 2023/04/15 23:02:15 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hud_crosshair(t_cub3d *cub)
{
	int		i;
	int		j;

	i = -CROSSHAIR_THICKNESS / 2;
	while (++i < CROSSHAIR_THICKNESS / 2)
	{
		j = 0;
		while (++j < CROSSHAIR_SIZE / 2 - CROSSHAIR_GAP)
			mlx_put_pixel(cub->mlx->hud_crosshair, j,
				CROSSHAIR_SIZE / 2 + i, CROSSHAIR_COLOR);
		j = CROSSHAIR_SIZE;
		while (--j > CROSSHAIR_SIZE / 2 + CROSSHAIR_GAP)
			mlx_put_pixel(cub->mlx->hud_crosshair, j,
				CROSSHAIR_SIZE / 2 + i, CROSSHAIR_COLOR);
		j = CROSSHAIR_SIZE;
		while (--j > CROSSHAIR_SIZE / 2 + CROSSHAIR_GAP)
			mlx_put_pixel(cub->mlx->hud_crosshair, CROSSHAIR_SIZE / 2 + i,
				j, CROSSHAIR_COLOR);
		if (CROSSHAIR_T)
			continue ;
		j = 0;
		while (++j < CROSSHAIR_SIZE / 2 - CROSSHAIR_GAP)
			mlx_put_pixel(cub->mlx->hud_crosshair, CROSSHAIR_SIZE / 2 + i,
				j, CROSSHAIR_COLOR);
	}
}
