/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:41:38 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 05:32:43 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hud_draw(t_cub3d *cub)
{
	ft_minimap_render_player(cub);
	ft_hud_ammo(cub);
	ft_hud_fps(cub);
}

void	ft_hud_init(t_cub3d *cub)
{
	ft_minimap_render(cub);
	ft_hud_crosshair(cub);
}
