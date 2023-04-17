/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:30:01 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It sets the x, y, and z values of a t_vector3 struct
 * 
 * @param self The vector3 object that is being set.
 * @param x The x value of the vector.
 * @param y The y coordinate of the vector.
 * @param z the z-coordinate of the vector
 */
void	ft_vector3_set(t_vector3 *self, int x, int y, int z)
{
	self->x = x;
	self->y = y;
	self->z = z;
}
