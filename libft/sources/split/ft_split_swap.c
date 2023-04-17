/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:26:02 by troudot           #+#    #+#             */
/*   Updated: 2023/04/05 02:54:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function swaps two strings in a string array
 * 
 * @param arr The array to be sorted
 * @param i the index of the first string to swap
 * @param j the index of the string you want to swap with i
 * 
 * @return A pointer to a char array.
 */
char	**ft_split_swap(char **arr, int i, int j)
{
	char	*tmp;
	char	*tmp2;

	if (!*arr || !arr || (i == j))
		return (0);
	if (ft_split_len(arr) < j || ft_split_len(arr) < i)
		return (0);
	tmp = ft_strdup(arr[j]);
	tmp2 = ft_strdup(arr[i]);
	arr = ft_split_overtype(arr, tmp2, j);
	arr = ft_split_overtype(arr, tmp, i);
	free(tmp);
	free(tmp2);
	return (arr);
}
