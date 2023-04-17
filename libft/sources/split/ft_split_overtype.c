/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_overtype.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:35:28 by lucas             #+#    #+#             */
/*   Updated: 2023/04/05 02:53:41 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * 
 * 
 * @param arr The array to be modified.
 * @param insert the string to insert
 * @param i the index of the array where the new string will be inserted
 * 
 * @return The array is being returned.
 */
char	**ft_split_overtype(char **arr, char *insert, size_t i)
{
	if (!insert || !arr)
		return (0);
	arr = ft_split_pop(arr, i);
	if (!arr)
		return (0);
	arr = ft_split_insert(arr, insert, i);
	return (arr);
}
