/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:50:36 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/31 11:43:52 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies a split string
 * 
 * @param str The string to be split.
 * 
 * @return A copy of the string array.
 */
char	**ft_split_copy(char **str)
{
	char	**s;
	int		i;

	if (!str)
		return (0);
	s = (char **) ft_calloc(ft_split_len(str) + 1, sizeof(char *));
	if (!s)
		return (0);
	i = -1;
	while (str[++i])
	{
		s[i] = ft_strdup(str[i]);
		if (!s[i])
			return (ft_split_error(s, i));
	}
	s[i] = 0;
	return (s);
}
