/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:43:30 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:46:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns 1 if all characters in the string s are accepted by the function f,
 * and 0 otherwise
 * 
 * @param s The string to iterate over.
 * @param f a function that takes an int and returns an int
 * 
 * @return A boolean value.
 */
int	ft_striter_if(char *s, int (*f)(int))
{
	if (!s || !f)
		return (0);
	while (*s)
		if (!f(*s++))
			return (0);
	return (1);
}
