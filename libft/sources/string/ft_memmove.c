/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:55:55 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:55:00 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the source and destination overlap, copy the source bytes to a temporary
 * buffer, then copy the
 * bytes from the temporary buffer to the destination
 * 
 * @param dst The destination string where the content is to be copied.
 * @param src The source string.
 * @param len The number of bytes to be moved.
 * 
 * @return A pointer to the destination string.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			*(char *)(dst + len) = *(char *)(src + len);
	else if (src >= dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
