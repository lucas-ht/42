/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ncopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:40:07 by lucas             #+#    #+#             */
/*   Updated: 2023/01/26 00:35:24 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies the first n strings from
 * str into a new array, and returns that array
 * 
 * @param str the string to split
 * @param n the number of strings to copy
 * 
 * @return A copy of the first n strings of the array str.
 */
char	**ft_split_ncopy(char **str, int n)
{
	char	**s;
	int		i;

	i = ft_split_len(str);
	s = (char **) ft_calloc(t(i > n, t(n > 0, n, 0), i) + 1, sizeof(char *));
	if (!s)
		return (0);
	i = -1;
	while (str[++i] && i < n)
	{
		s[i] = ft_strdup(str[i]);
		if (!s[i])
			return (ft_split_error(s, i));
	}
	s[i] = 0;
	return (s);
}
