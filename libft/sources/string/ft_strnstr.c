/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:20:54 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:57:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the first character of needle is found in haystack, then check if the rest
 * of needle is found in
 * haystack starting at the same index
 * 
 * @param haystack The string to search in
 * @param needle the string to find
 * @param len the maximum number of characters to search
 * 
 * @return A pointer to the first occurrence of the substring needle
 * in the string haystack, or a null
 * pointer if the substring is not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
			if (!needle[++j])
				return ((char *) haystack + i);
		i++;
	}
	return (0);
}
