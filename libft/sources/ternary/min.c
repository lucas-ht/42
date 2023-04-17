/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:39:09 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:58:43 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Min() returns the minimum of two integers.
 * 
 * @param a The first integer to compare.
 * @param b the number of blocks
 * 
 * @return The minimum of two integers.
 */
int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
