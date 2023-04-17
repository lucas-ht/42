/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:05:16 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:16 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns a copy of the vector passed as a parameter
 * 
 * @param v The vector to copy.
 * 
 * @return A new vector3 with the same values as the one passed in.
 */
t_vector3	ft_vector3_copy(t_vector3 v)
{
	return (ft_vector3_new(v.x, v.y, v.z));
}
