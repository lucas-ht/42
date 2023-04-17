/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_overtype_split.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:24:42 by troudot           #+#    #+#             */
/*   Updated: 2023/04/05 02:53:59 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes an array of strings, and inserts another array of strings
 * into it at a given index
 * 
 * @param arr the array to be modified
 * @param insert The array of strings to insert into the array.
 * @param i the index of the array to be replaced
 * 
 * @return a pointer to a pointer to a char.
 */
char	**ft_split_overtype_split(char **arr, char **insert, size_t i)
{
	size_t	j;

	if (!insert || !arr)
		return (0);
	j = -1;
	arr = ft_split_pop(arr, i);
	if (!arr)
		return (0);
	while (insert[++j])
	{
		arr = ft_split_insert(arr, insert[j], i + j);
		if (!arr)
			return (0);
	}
	return (arr);
}
