/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:21:51 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:57:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It allocates a new string, copies the first n characters of s1 into it,
 * and returns a pointer to it
 * 
 * @param s1 The string to be copied.
 * @param n the number of characters to copy
 * 
 * @return A pointer to a new string.
 */
char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		i;

	if (!s1 || n <= 0)
		return (0);
	n = min(ft_strlen(s1), n);
	str = (char *) malloc((n + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (++i < n)
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
