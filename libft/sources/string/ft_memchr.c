/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:07:47 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:54:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_memchr() locates the first occurrence of c
 * (converted to an unsigned char) in string
 * s
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * @param n The number of bytes to be checked.
 * 
 * @return A pointer to the first occurrence of the character c in
 * the first n bytes of the string
 * pointed to, by the argument str.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n--)
	{
		if (*str == (char) c)
			return ((void *) str);
		str++;
	}
	return (0);
}
