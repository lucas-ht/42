/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:45:53 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:04:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_weapon_idle(t_cub3d *cub)
{
	if (cub->mlx->weapon)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->weapon);
	cub->mlx->weapon = ft_mlx_texture_image(cub->mlx->mlx,
			cub->player->weapon.data->idle, (t_vector3){-200, -200, 0, 0});
	mlx_set_instance_depth(cub->mlx->weapon->instances, 10);
}

static void	ft_weapon_fire(t_cub3d *cub)
{
	if (cub->player->weapon.frame == cub->player->weapon.data->fire_count
		|| !cub->player->weapon.ammo)
	{
		cub->player->weapon.state = WEAPON_IDLE;
		cub->player->weapon.frame = 0;
		return ;
	}
	if (!cub->player->weapon.frame)
		cub->player->weapon.ammo--;
	if (cub->mlx->weapon)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->weapon);
	cub->mlx->weapon = ft_mlx_texture_image(cub->mlx->mlx,
			cub->player->weapon.data->fire[cub->player->weapon.frame++],
			(t_vector3){-200, -200, 0, 0});
	mlx_set_instance_depth(cub->mlx->weapon->instances, 10);
}

static void	ft_weapon_reload(t_cub3d *cub)
{
	if (cub->player->weapon.frame == cub->player->weapon.data->reload_count)
	{
		cub->player->weapon.state = WEAPON_IDLE;
		cub->player->weapon.frame = 0;
		cub->player->weapon.ammo = cub->player->weapon.data->ammo_count;
		return ;
	}
	if (cub->mlx->weapon)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->weapon);
	cub->mlx->weapon = ft_mlx_texture_image(cub->mlx->mlx,
			cub->player->weapon.data->reload[cub->player->weapon.frame++],
			(t_vector3){-200, -200, 0, 0});
	mlx_set_instance_depth(cub->mlx->weapon->instances, 10);
}

static void	ft_weapon_inspect(t_cub3d *cub)
{
	if (cub->player->weapon.frame == cub->player->weapon.data->inspect_count)
	{
		cub->player->weapon.state = WEAPON_IDLE;
		cub->player->weapon.frame = 0;
		return ;
	}
	if (cub->mlx->weapon)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->weapon);
	cub->mlx->weapon = ft_mlx_texture_image(cub->mlx->mlx,
			cub->player->weapon.data->inspect[cub->player->weapon.frame++],
			(t_vector3){-200, -200, 0, 0});
	mlx_set_instance_depth(cub->mlx->weapon->instances, 10);
}

void	ft_weapon_render(t_cub3d *cub)
{
	static double	previous_time = 0;

	if (mlx_get_time() < previous_time + 0.06)
		return ;
	previous_time = mlx_get_time();
	if (cub->player->weapon.state == WEAPON_IDLE)
		ft_weapon_idle(cub);
	if (cub->player->weapon.state == WEAPON_FIRE)
		ft_weapon_fire(cub);
	if (cub->player->weapon.state == WEAPON_RELOAD)
		ft_weapon_reload(cub);
	if (cub->player->weapon.state == WEAPON_INSPECT)
		ft_weapon_inspect(cub);
}
