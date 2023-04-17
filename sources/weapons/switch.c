/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:33:59 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:04:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_weapon_action(t_cub3d *cub, t_weapon_state state)
{
	cub->player->weapon.state = state;
	cub->player->weapon.frame = 0;
}

void	ft_weapon_switch(t_cub3d *cub, unsigned int id)
{
	if (id >= WEAPON_NUMBER)
		return ;
	cub->player->weapon.id = id;
	cub->player->weapon.state = WEAPON_IDLE;
	cub->player->weapon.frame = 0;
	cub->player->weapon.ammo = cub->weapons[id].ammo_count;
	cub->player->weapon.data = &cub->weapons[id];
	if (cub->mlx->weapon)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->weapon);
	ft_weapon_hud(cub);
}
