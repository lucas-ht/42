/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_insert_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:46:12 by troudot           #+#    #+#             */
/*   Updated: 2023/03/31 08:35:49 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It inserts a string into a string array at a given index
 * 
 * @param arr The array to insert into.
 * @param insert the array of strings to insert
 * @param i the index of the array to insert the split into
 * 
 * @return A pointer to a char array.
 */
char	**ft_split_insert_split(char **arr, char **insert, size_t i)
{
	size_t	j;

	if (!insert || !arr)
		return (0);
	j = -1;
	while (insert[++j])
	{
		arr = ft_split_insert(arr, insert[j], i + j);
		if (!arr)
			return (0);
	}
	return (arr);
}
