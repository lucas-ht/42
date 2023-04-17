/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:25:18 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It creates a new vector3 and sets its values to x, y, and z.
 * 
 * @param x The x value of the vector
 * @param y The y coordinate of the vector.
 * @param z the z-coordinate of the vector
 */
t_vector3	ft_vector3_new(int x, int y, int z)
{
	t_vector3	v;

	v.set = ft_vector3_set;
	v.set(&v, x, y, z);
	return (v);
}
