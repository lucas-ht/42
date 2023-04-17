/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 05:09:53 by lucas             #+#    #+#             */
/*   Updated: 2023/04/14 06:30:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * The function handles player movement based on keyboard input and checks
 * for collisions with walls in a 2D map.
 * 
 * @param cub The parameter "cub" is a pointer to a struct of type "t_cub3d",
 * which contains information about the game state and settings.
 */
void	ft_hook_movement(t_cub3d *cub)
{
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_W))
		ft_movement_forward(cub);
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_S))
		ft_movement_backward(cub);
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_D))
		ft_movement_right(cub);
	if (mlx_is_key_down(cub->mlx->mlx, MLX_KEY_A))
		ft_movement_left(cub);
}
