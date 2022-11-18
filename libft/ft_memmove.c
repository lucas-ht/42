/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:55:55 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/18 03:10:16 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
