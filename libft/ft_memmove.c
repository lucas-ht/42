/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:55:55 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/03 23:22:17 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (!dst && !src)
		return (dst);
	d = (char *) dst;
	s = (char *) src;
	if (src < dst)
	{
		s += len - 1;
		d += len - 1;
		while (len--)
			*d-- = *s--;
	}
	else if (src >= dst)
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
