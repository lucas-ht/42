/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:49:24 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:55:48 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_strchr() locates the first occurrence of c
 * in the string
 * pointed to by s
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character c in the string s.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (unsigned char) c)
		if (!*s++)
			return (0);
	return ((char *) s);
}
