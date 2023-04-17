/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:09:53 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 04:43:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * The function updates the player's angle based on the left and right
 * arrow keys being pressed.
 * 
 * @param cub The parameter "cub" is a pointer to a struct of type "t_cub3d".
 */
void	ft_hook_angle_key(t_cub3d *cub)
{
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_LEFT))
		cub->player->angle.y -= 10 * PLAYER_SENSITIVITY;
	else if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_RIGHT))
		cub->player->angle.y += 10 * PLAYER_SENSITIVITY;
	cub->player->angle = ft_euler_normalize(cub->player->angle);
}

/**
 * The function updates the player's angle based on the left and right
 * arrow keys being pressed.
 * 
 * @param cub The parameter "cub" is a pointer to a struct of type "t_cub3d".
 */
void	ft_hook_angle_mouse(t_cub3d *cub, t_vector3 delta)
{
	if (!PLAYER_MOUSE)
		return ;
	cub->player->angle.y += delta.x * PLAYER_SENSITIVITY;
	cub->player->angle = ft_euler_normalize(cub->player->angle);
}
