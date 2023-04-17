/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_longest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:31:28 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:19:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function returns the length of the longest string in a given array
 * of strings.
 * 
 * @param arr The parameter `arr` is a pointer to a pointer to a character,
 * which represents an array
 * of strings.
 * 
 * @return The function `ft_split_longest` is returning a `size_t` value,
 * which represents the length
 * of the longest string in the array `arr`.
 */
size_t	ft_split_longest(char **arr)
{
	size_t	res;
	int		i;

	if (!arr || !*arr)
		return (0);
	i = -1;
	res = ft_strlen(arr[0]);
	while (arr[++i])
		if (ft_strlen(arr[i]) > res)
			res = ft_strlen(arr[i]);
	return (res);
}
