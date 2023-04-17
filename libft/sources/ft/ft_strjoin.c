/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:37:32 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:47:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes two strings, and returns a new string that is the concatenation of
 * the two strings
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to a new string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 && !s2)
		return (0);
	s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (0);
	if (s1)
		ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	if (!s2)
		return (s);
	if (s2)
		ft_strlcpy(s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s);
}
