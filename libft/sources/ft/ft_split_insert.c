/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:35:28 by lucas             #+#    #+#             */
/*   Updated: 2023/01/31 03:18:37 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It inserts a string into a split string array
 * 
 * @param strs The array of strings to insert into.
 * @param str the string to insert
 * @param i the index of the new string
 * 
 * @return A pointer to a pointer to a char.
 */
char	**ft_split_insert(char **strs, char *str, int i)
{
	char	**new;
	int		j;
	int		k;

	if (!strs || !str || i > ft_split_len(strs))
		return (ft_free_split(strs), (void *) 0);
	new = (char **) ft_calloc(ft_split_len(strs) + 3, sizeof(char *));
	if (!new)
		return (ft_free_split(strs), (void *) 0);
	new[i] = ft_strdup(str);
	if (!new[i])
		return (ft_free_split(strs), free(new), (void *) 0);
	j = 0;
	k = -1;
	while (++k >= 0 && strs[j])
	{
		if (k == i)
			continue ;
		new[k] = ft_strdup(strs[j++]);
		if (!new[k])
			return (ft_free_split(strs), ft_split_error(new, k));
	}
	new[k + 1] = 0;
	ft_free_split(strs);
	return (new);
}
