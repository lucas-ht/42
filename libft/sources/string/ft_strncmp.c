/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:00:21 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:56:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function compares the first n characters of the strings s1 and s2
 * 
 * @param s1 The first string to be compared.
 * @param s2 The string to compare to.
 * @param n The number of characters to compare.
 * 
 * @return The difference between the first two characters that differ in the
 * strings s1 and s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (*s1 == *s2 && --n && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
