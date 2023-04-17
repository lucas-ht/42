/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:58:55 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:59:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If condition is true, return a, otherwise return b.
 * 
 * @param condition The condition to test.
 * @param a The first number to compare.
 * @param b the number of bytes to read
 * 
 * @return the value of a if the condition is true, otherwise it
 * returns the value of b.
 */
int	t(int condition, int a, int b)
{
	if (condition)
		return (a);
	else
		return (b);
}
