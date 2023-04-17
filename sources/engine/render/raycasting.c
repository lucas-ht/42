/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:28:46 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 08:36:03 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_card	ft_cardinal_ws(t_cub3d *cub, t_vector3 angle, t_vector3 pos)
{
	t_elem		elem;

	if (angle.y >= 180 - PLAYER_FOV)
	{
		elem = ft_map_at(cub, pos.x + 1, pos.y + 10);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_SOUTH);
		elem = ft_map_at(cub, pos.x + 1, pos.y - 10);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_NORTH);
		return (C_WEST);
	}
	if (angle.y >= 90 - PLAYER_FOV)
	{
		elem = ft_map_at(cub, pos.x - 10, pos.y - 1);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_WEST);
		elem = ft_map_at(cub, pos.x + 10, pos.y - 1);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_EAST);
		return (C_SOUTH);
	}
	return (C_SOUTH);
}

/**
 * The function returns a cardinal direction based on a given angle.
 * 
 * @param angle The parameter `angle` is a `t_vector3` data type,
 * which represents a 3D vector containing the angles of rotation
 * around the x, y,
 * and z axes. In this function, only the `y` angle
 * is used to determine the cardinal direction.
 * 
 * @return a value of type `t_card`, which is an
 * enumerated type representing the cardinal direction
 * (north, south, east, or west) based on the given angle.
 */
static t_card	ft_cardinal_en(t_cub3d *cub, t_vector3 angle, t_vector3 pos)
{
	t_elem		elem;

	if (angle.y >= 360 - PLAYER_FOV)
	{
		elem = ft_map_at(cub, pos.x - 1, pos.y + 10);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_SOUTH);
		elem = ft_map_at(cub, pos.x - 1, pos.y - 10);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_NORTH);
		return (C_EAST);
	}
	if (angle.y >= 270 - PLAYER_FOV)
	{
		elem = ft_map_at(cub, pos.x - 10, pos.y + 1);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_WEST);
		elem = ft_map_at(cub, pos.x + 10, pos.y + 1);
		if (elem == M_WALL || elem == M_DOOR)
			return (C_EAST);
		return (C_NORTH);
	}
	return (ft_cardinal_ws(cub, angle, pos));
}

static t_trace	ft_raycast(t_cub3d *cub, int angle)
{
	int			distance;
	t_trace		trace;

	distance = -1;
	while (++distance < RAY_DISTANCE)
	{
		trace.vec = cub->player->angle;
		trace.vec.y += angle * PLAYER_FOV / RAY_NUMBER - RAY_TOLERENCE / 2;
		trace.vec = ft_euler_normalize(trace.vec);
		trace.vec = ft_angle_polar(trace.vec, distance);
		trace.vec = ft_vector3_add(trace.vec, cub->player->pos);
		trace.elem = ft_map_at(cub, trace.vec.x, trace.vec.y);
		trace.angle.x = 0;
		trace.angle.y = angle * PLAYER_FOV / RAY_NUMBER;
		trace.angle.z = 0;
		if (trace.elem == M_WALL || trace.elem == M_DOOR)
			break ;
	}
	trace.distance = distance;
	trace.pos = ft_vector3_new((int) trace.vec.x / MAP_MULTIPIER,
			(int) trace.vec.y / MAP_MULTIPIER, 0);
	trace.card = ft_cardinal_en(cub,
			ft_euler_normalize(cub->player->angle), trace.vec);
	return (trace);
}

/**
 * The function performs raycasting to determine the distance and
 * location of walls in a 3D game world.
 * 
 * @param cub The parameter "cub" is a pointer to a struct of type
 * "t_cub3d", which contains
 * information about the game world and the player's
 * position and orientation.
 */
void	ft_raycasting(t_cub3d *cub)
{
	int			angle;
	t_trace		trace;

	angle = 0;
	while (++angle < RAY_NUMBER + RAY_TOLERENCE)
	{
		trace = ft_raycast(cub, angle);
		cub->traces[angle] = trace;
	}
}
