/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:36:17 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:58:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If condition is true, return a, else return b.
 * 
 * @param condition The condition to test.
 * @param a The first parameter to return if the condition is true.
 * @param b the value to return if the condition is false
 * 
 * @return The first argument if the condition is true,
 * otherwise the second argument.
 */
void	*t_p(int condition, void *a, void *b)
{
	if (condition)
		return (a);
	else
		return (b);
}
