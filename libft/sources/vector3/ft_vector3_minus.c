/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:30:58 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns a new vector that is the difference of two vectors
 * 
 * @param v The first vector
 * @param w the vector to subtract from v
 * 
 * @return A new vector3 with the subtraction of the two vectors.
 */
t_vector3	ft_vector3_minus(t_vector3 v, t_vector3 w)
{
	return (ft_vector3_new(v.x - w.x, v.y - w.y, v.z - w.z));
}
