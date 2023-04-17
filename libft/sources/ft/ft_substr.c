/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:33:28 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:48:03 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * "ft_substr() returns a pointer to a new string which is a substring
 * of the string 's' starting at
 * index 'start' and of length 'len'."
 * 
 * The first thing we do is check if the string 's' is NULL. If it is,
 * we return NULL
 * 
 * @param s The string to be cut
 * @param start the index of the first character to include in the substring.
 * @param len the length of the substring
 * 
 * @return A pointer to a new string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		len = 0;
		start = ft_strlen(s);
	}
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
