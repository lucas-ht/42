/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:04:12 by lucas             #+#    #+#             */
/*   Updated: 2023/01/25 20:29:02 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string array,
 * and removes the string at index i, returning a new string array
 * 
 * @param strs The array of strings to be modified.
 * @param i the index of the string to be removed
 * 
 * @return A pointer to a pointer to a char.
 */
char	**ft_split_pop(char **strs, int i)
{
	char	**s;
	int		j;
	int		k;

	s = (char **) ft_calloc(ft_split_len(strs), sizeof(char *));
	if (!s)
		return (ft_free_split(strs), (void *) 0);
	j = -1;
	k = -1;
	while (strs[++j])
	{
		if (j == i)
			continue ;
		s[++k] = ft_strdup(strs[j]);
		if (!s[k])
			return (ft_free_split(strs), ft_split_error(s, k));
	}
	s[k + 1] = 0;
	ft_free_split(strs);
	return (s);
}
