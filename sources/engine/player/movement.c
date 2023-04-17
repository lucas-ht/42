/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 06:30:59 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 02:01:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_movement(t_cub3d *cub, t_vector3 v)
{
	t_elem		elem;

	elem = ft_map_at(cub, (cub->player->pos.x + v.x),
			cub->player->pos.y);
	if (elem != M_WALL && elem != M_DOOR)
		cub->player->pos.x += v.x;
	elem = ft_map_at(cub, cub->player->pos.x,
			(cub->player->pos.y + v.y));
	if (elem != M_WALL && elem != M_DOOR)
		cub->player->pos.y += v.y;
}

void	ft_movement_forward(t_cub3d *cub)
{
	t_vector3	next;

	next = ft_vector3_add(cub->player->angle,
			ft_vector3_new(0, (PLAYER_FOV / 2), 0));
	next = ft_euler_normalize(next);
	next = ft_angle_polar(next, PLAYER_VELOCITY);
	ft_movement(cub, next);
}

void	ft_movement_backward(t_cub3d *cub)
{
	t_vector3	next;

	next = ft_vector3_add(cub->player->angle,
			ft_vector3_new(0, 180 + (PLAYER_FOV / 2), 0));
	next = ft_euler_normalize(next);
	next = ft_angle_polar(next, PLAYER_VELOCITY);
	ft_movement(cub, next);
}

void	ft_movement_right(t_cub3d *cub)
{
	t_vector3	next;

	next = ft_vector3_add(cub->player->angle,
			ft_vector3_new(0, 90 + (PLAYER_FOV / 2), 0));
	next = ft_euler_normalize(next);
	next = ft_angle_polar(next, PLAYER_VELOCITY);
	ft_movement(cub, next);
}

void	ft_movement_left(t_cub3d *cub)
{
	t_vector3	next;

	next = ft_vector3_add(cub->player->angle,
			ft_vector3_new(0, 270 + (PLAYER_FOV / 2), 0));
	next = ft_euler_normalize(next);
	next = ft_angle_polar(next, PLAYER_VELOCITY);
	ft_movement(cub, next);
}
