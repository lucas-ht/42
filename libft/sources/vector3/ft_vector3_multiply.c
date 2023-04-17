/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:30:58 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It multiplies a vector by a scalar
 * 
 * @param v The vector to multiply.
 * @param k The scalar value to multiply the vector by.
 * 
 * @return A new vector3 with the x, y, and z values multiplied by k.
 */
t_vector3	ft_vector3_multiply(t_vector3 v, int k)
{
	return (ft_vector3_new(v.x * k, v.y * k, v.z * k));
}
