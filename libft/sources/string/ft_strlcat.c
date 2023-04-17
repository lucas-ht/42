/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:40:33 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:56:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_strlcat() appends the null-terminated string src to the end of
 * dst. It will append
 * at most dstsize - strlen(dst) - 1 bytes, NUL-terminating the result
 * 
 * @param dst The destination string.
 * @param src The string to be appended.
 * @param dstsize The size of the destination buffer.
 * 
 * @return The length of the string it tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (!dstsize)
		return (slen);
	if (dstsize < dlen)
		slen += dstsize;
	else
		slen += dlen;
	i = 0;
	while (src[i] && dlen + i < dstsize - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = 0;
	return (slen);
}
