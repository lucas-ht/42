/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:55:36 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:57:31 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns a pointer to the last occurrence of the character c in
 * the string s.
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the last occurrence of the character c in the string s
 */
char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char) c)
		if (!i--)
			return (0);
	return ((char *)(s + i));
}
