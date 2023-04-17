/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:02:28 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:04:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hud_ammo(t_cub3d *cub)
{
	char	*ammo_text;
	char	*ammo_text_max;

	if (cub->mlx->hud_ammo)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->hud_ammo);
	if (!cub->player->weapon.data->ammo_count)
		return ;
	ammo_text = ft_itoa(cub->player->weapon.ammo);
	ammo_text = ft_strjoin_free(ammo_text, " / ");
	ammo_text_max = ft_itoa(cub->player->weapon.data->ammo_count);
	ammo_text = ft_strjoin_free(ammo_text, ammo_text_max);
	free(ammo_text_max);
	cub->mlx->hud_ammo = mlx_put_string(
			cub->mlx->mlx, ammo_text, 20, HEIGHT - WEAPON_NUMBER * 80 - 40);
	free(ammo_text);
}
