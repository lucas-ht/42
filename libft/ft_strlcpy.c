/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:13:10 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/02 21:39:48 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (src_len >= dstsize)
		len = dstsize - 1;
	else
		len = src_len;
	ft_memcpy(dst, src, len);
	dst[len] = 0;
	return (src_len);
}
