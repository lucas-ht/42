/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:27:08 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:04:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_weapon_hud(t_cub3d *cub)
{
	int				i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < WEAPON_NUMBER)
	{
		if (cub->weapons[i].hud)
			mlx_delete_image(cub->mlx->mlx, cub->weapons[i].hud);
		texture = cub->weapons[i].hud_unselected;
		if (i == (int) cub->player->weapon.id)
			texture = cub->weapons[i].hud_selected;
		cub->weapons[i].hud = ft_mlx_texture_image(cub->mlx->mlx,
				texture, (t_vector3){20, HEIGHT - (i + 1) * 80, 0, 0});
		mlx_set_instance_depth(cub->weapons[i].hud->instances, 8 + i);
		i++;
	}
}
