/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:39:58 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:58:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Max returns the larger of two integers.
 * 
 * @param a The first integer to compare.
 * @param b the number of bottles of beer on the wall
 * 
 * @return The max of two numbers
 */
int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
