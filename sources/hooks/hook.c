/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:13:06 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 13:41:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_hook_loop(void *cub3d)
{
	t_cub3d		*cub;

	cub = (t_cub3d *) cub3d;
	ft_mlx_loader(cub);
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx->mlx);
	if (cub->loader < 1)
		return ;
	ft_hook_movement(cub);
	ft_hook_angle_key(cub);
	ft_hud_draw(cub);
	ft_raycasting(cub);
	ft_render_map(cub);
	ft_weapon_render(cub);
	ft_hud_fps(cub);
}

static void	ft_hook_key(mlx_key_data_t keydata, void *cub3d)
{
	t_cub3d		*cub;

	cub = (t_cub3d *) cub3d;
	if (cub->loader < 1)
		return ;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		ft_map_door_open(cub);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		ft_weapon_action(cub, WEAPON_FIRE);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_weapon_action(cub, WEAPON_RELOAD);
	if (keydata.key == MLX_KEY_F && keydata.action == MLX_PRESS)
		ft_weapon_action(cub, WEAPON_INSPECT);
	if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
		ft_weapon_switch(cub, W_M4);
	if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
		ft_weapon_switch(cub, W_KNIFE);
	if (keydata.key != MLX_KEY_T || keydata.action != MLX_PRESS)
		return ;
	cub->mlx->mouse = !cub->mlx->mouse;
	mlx_set_cursor_mode(cub->mlx->mlx, t(cub->mlx->mouse,
			MLX_MOUSE_NORMAL, MLX_MOUSE_DISABLED));
}

static void	ft_hook_cursor(double x, double y, void *cub3d)
{
	t_cub3d				*cub;
	static t_vector3	prev;
	static t_vector3	delta;

	cub = (t_cub3d *) cub3d;
	if (cub->loader < 1)
		return ;
	if (!prev.x)
		prev.x = x;
	if (!prev.y)
		prev.y = y;
	delta.x = x - prev.x;
	delta.y = y - prev.y;
	ft_hook_angle_mouse(cub, delta);
	prev.x = x;
	prev.y = y;
}

static void	ft_hook_mouse(mouse_key_t key, action_t action,
			modifier_key_t mod, void *cub3d)
{
	t_cub3d		*cub;

	cub = (t_cub3d *) cub3d;
	if (cub->loader < 1)
		return ;
	(void) mod;
	if (key == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		ft_weapon_action(cub, WEAPON_FIRE);
}

void	ft_hook(t_cub3d *cub)
{
	if (!mlx_loop_hook(cub->mlx->mlx, ft_hook_loop, (void *) cub))
		ft_error(ERROR_MLX);
	mlx_key_hook(cub->mlx->mlx, ft_hook_key, (void *) cub);
	mlx_cursor_hook(cub->mlx->mlx, ft_hook_cursor, (void *) cub);
	mlx_mouse_hook(cub->mlx->mlx, ft_hook_mouse, (void *) cub);
}
