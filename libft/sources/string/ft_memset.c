/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:34:15 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:55:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_memset() takes a pointer to a memory area, a byte value, and a size,
 * and fills the memory area
 * with the given byte value
 * 
 * @param b This is the pointer to the memory area to be filled.
 * @param c the character to fill the memory with
 * @param len the number of bytes to fill
 * 
 * @return A pointer to the first byte of the memory area b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(char *)(b + i++) = (char) c;
	return (b);
}
