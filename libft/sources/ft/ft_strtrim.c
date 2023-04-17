/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:50:13 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:47:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

/**
 * It returns a copy of the string s1, without any characters in set
 * appearing at the start or end of
 * the string
 * 
 * @param s1 The string to be trimmed.
 * @param set the set of characters to trim
 * 
 * @return A pointer to a new string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len;
	char			*start;
	char			*end;
	char			*str;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_char_in_set(*s1, set))
		s1++;
	start = (char *) s1;
	end = (char *) s1 + (ft_strlen(s1) - 1) * sizeof(char);
	while (end != start && ft_char_in_set(*end, set))
		end--;
	len = end - start + 2;
	if (end == start)
		len = 2;
	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, start, len);
	return (str);
}
