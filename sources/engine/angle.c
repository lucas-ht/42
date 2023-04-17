/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 06:56:45 by lucas             #+#    #+#             */
/*   Updated: 2023/04/14 01:58:10 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_angle_rad(double angle)
{
	return (angle * M_PI / 180);
}

t_vector3	ft_angle_polar(t_vector3 angle, double distance)
{
	t_vector3	polar;

	polar.x = distance * cos(ft_angle_rad(angle.y));
	polar.y = distance * sin(ft_angle_rad(angle.y));
	polar.z = 0;
	return (polar);
}
