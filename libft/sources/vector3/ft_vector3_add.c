/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 04:30:58 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It adds two vectors together
 * 
 * @param v The first vector to add.
 * @param w the vector to add to v
 * 
 * @return A new vector3 with the sum of the two vectors.
 */
t_vector3	ft_vector3_add(t_vector3 v, t_vector3 w)
{
	return (ft_vector3_new(v.x + w.x, v.y + w.y, v.z + w.z));
}
