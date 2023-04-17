/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:30:58 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:22 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns the dot product of two vectors
 * 
 * @param v The first vector.
 * @param w the vector to be added to v
 * 
 * @return The dot product of two vectors.
 */
int	ft_vector3_dot(t_vector3 v, t_vector3 w)
{
	return (v.x * w.x + v.y * w.y + v.z * w.z);
}
