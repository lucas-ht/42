/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:53:36 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 03:36:16 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hud_intro(t_mlx	*mlx)
{
	mlx->intro_texture = ft_mlx_texture_png(TEXTURE_PATH_HUD "intro.png");
	mlx->intro = ft_mlx_texture_image(mlx->mlx, mlx->intro_texture,
			(t_vector3){0, 0, 0, 0});
	mlx_set_instance_depth(mlx->intro->instances, 6);
	mlx_resize_image(mlx->intro, WIDTH, HEIGHT * 2);
}
