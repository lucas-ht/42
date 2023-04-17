/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:53:16 by lucas             #+#    #+#             */
/*   Updated: 2023/04/17 19:05:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_weapon_m4(t_cub3d *cub)
{
	cub->weapons[W_M4] = (t_weapon_data){W_M4, W_M4_NAME,
		W_M4_AMMO, W_M4_FIRE, W_M4_RELOAD, W_M4_INSPECT,
		0, 0, 0, 0, 0, 0, 0};
	cub->weapons[W_M4].hud_selected = ft_mlx_texture_png(
			WEAPON_PATH "M4/M4_hud_selected.png");
	cub->weapons[W_M4].hud_unselected = ft_mlx_texture_png(
			WEAPON_PATH "M4/M4_hud_unselected.png");
	cub->weapons[W_M4].idle = ft_mlx_texture_png(
			WEAPON_PATH "M4/M4_idle.png");
	cub->weapons[W_M4].fire = ft_mlx_textures_png(
			WEAPON_PATH "M4/fire/M4_fire", W_M4_FIRE);
	cub->weapons[W_M4].reload = ft_mlx_textures_png(
			WEAPON_PATH "M4/reload/M4_reload", W_M4_RELOAD);
	cub->weapons[W_M4].inspect = ft_mlx_textures_png(
			WEAPON_PATH "M4/inspect/M4_inspect", W_M4_INSPECT);
}

static void	ft_weapon_knife(t_cub3d *cub)
{
	cub->weapons[W_KNIFE] = (t_weapon_data){W_KNIFE, W_KNIFE_NAME,
		W_KNIFE_AMMO, W_KNIFE_FIRE, W_KNIFE_RELOAD, W_KNIFE_INSPECT,
		0, 0, 0, 0, 0, 0, 0};
	cub->weapons[W_KNIFE].hud_selected = ft_mlx_texture_png(
			WEAPON_PATH "Knife/Knife_hud_selected.png");
	cub->weapons[W_KNIFE].hud_unselected = ft_mlx_texture_png(
			WEAPON_PATH "Knife/Knife_hud_unselected.png");
	cub->weapons[W_KNIFE].idle = ft_mlx_texture_png(
			WEAPON_PATH "Knife/Knife_idle.png");
	cub->weapons[W_KNIFE].fire = ft_mlx_textures_png(
			WEAPON_PATH "Knife/fire/Knife_fire", W_KNIFE_FIRE);
	cub->weapons[W_KNIFE].reload = ft_mlx_textures_png(
			WEAPON_PATH "Knife/reload/Knife_reload", W_KNIFE_RELOAD);
	cub->weapons[W_KNIFE].inspect = ft_mlx_textures_png(
			WEAPON_PATH "Knife/inspect/Knife_inspect", W_KNIFE_INSPECT);
}

void	ft_weapon_init(t_cub3d *cub)
{
	ft_weapon_m4(cub);
	ft_weapon_knife(cub);
	ft_weapon_switch(cub, W_M4);
}

void	ft_weapon_free(t_cub3d *cub)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < WEAPON_NUMBER)
	{
		mlx_delete_texture(cub->weapons[i].hud_selected);
		mlx_delete_texture(cub->weapons[i].hud_unselected);
		mlx_delete_texture(cub->weapons[i].idle);
		j = 0;
		while (j < cub->weapons[i].fire_count)
			mlx_delete_texture(cub->weapons[i].fire[j++]);
		free(cub->weapons[i].fire);
		j = 0;
		while (j < cub->weapons[i].reload_count)
			mlx_delete_texture(cub->weapons[i].reload[j++]);
		free(cub->weapons[i].reload);
		j = 0;
		while (j < cub->weapons[i].inspect_count)
			mlx_delete_texture(cub->weapons[i].inspect[j++]);
		free(cub->weapons[i].inspect);
		i++;
	}
}
