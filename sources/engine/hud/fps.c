/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:50:07 by lucas             #+#    #+#             */
/*   Updated: 2023/04/15 23:40:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hud_fps(t_cub3d *cub)
{
	static double	previous_time = 0;
	static double	fps = 0;
	double			current_time;
	char			*fps_text;

	current_time = mlx_get_time();
	fps = 1 / (current_time - previous_time);
	previous_time = current_time;
	if (cub->mlx->hud_fps)
		mlx_delete_image(cub->mlx->mlx, cub->mlx->hud_fps);
	fps_text = ft_itoa(fps);
	cub->mlx->hud_fps = mlx_put_string(cub->mlx->mlx, fps_text, WIDTH - 50, 10);
	mlx_set_instance_depth(cub->mlx->hud_fps->instances, 12);
	free(fps_text);
}
