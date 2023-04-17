/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_concatenate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:43:31 by lucas             #+#    #+#             */
/*   Updated: 2023/04/05 02:54:26 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It concatenates all the strings in 
 *  NULL-terminated array of strings
 * 
 * @param strs an array of strings
 * 
 * @return A string.
 */
/**
 * It concatenates all the strings in 
 *  NULL-terminated array of strings
 * 
 * @param strs an array of strings
 * 
 * @return A string.
 */
char	*ft_split_concatenate(char **strs, char *delimiter)
{
	char	*s;
	int		i;

	if (!strs)
		return (0);
	s = 0;
	i = -1;
	while (strs[++i])
	{
		s = ft_strjoin_free(s, strs[i]);
		if (strs[i + 1] && delimiter)
			s = ft_strjoin_free(s, delimiter);
	}
	return (s);
}
