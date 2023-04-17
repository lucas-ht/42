/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:20:19 by lucas             #+#    #+#             */
/*   Updated: 2023/04/12 23:27:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function normalizes a 3D vector by dividing its components by
 * its magnitude.
 * 
 * @param v v is a variable of type t_vector3, which represents a 3D vector
 * with x, y, and z components.
 * @param sqrt The sqrt parameter is a pointer to a function that takes a
 * double as input and returns its square root.
 * This allows the function to use different implementations of the square root
 * function, depending on the needs of the program.
 * 
 * @return The function `ft_vector3_normalize` is returning a
 * normalized `t_vector3` structure.
 */
t_vector3	ft_vector3_normalize(t_vector3 v, double (*sqrt)(double))
{
	double	n;

	n = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (ft_vector3_new(v.x / n, v.y / n, v.z / n));
}
