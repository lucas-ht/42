/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:13:10 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:56:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy the string pointed to by src, including the terminating null byte ('\0'),
 * to the buffer pointed
 * to by dst
 * 
 * @param dst The destination string.
 * @param src The string to copy from.
 * @param dstsize The size of the destination buffer.
 * 
 * @return The length of the string src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	if (len >= dstsize)
		len = dstsize - 1;
	ft_memcpy(dst, src, len);
	dst[len] = 0;
	return (ft_strlen(src));
}
