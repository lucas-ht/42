/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:52:39 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:54:49 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy n bytes from memory area src to memory area dst
 * 
 * @param dst The destination string where the content is to be copied.
 * @param src The source string.
 * @param n The number of bytes to copy.
 * 
 * @return The address of the destination string.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dst && !src)
		return (0);
	d = (char *) dst;
	s = (char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
