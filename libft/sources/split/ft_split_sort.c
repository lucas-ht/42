/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:26:45 by troudot           #+#    #+#             */
/*   Updated: 2023/04/05 02:54:32 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It sorts an array of strings
 * 
 * @param arr the array to sort
 * 
 * @return The array is being returned.
 */
char	**ft_split_sort(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (0);
	i = -1;
	while (arr[++i + 1])
	{
		if (ft_strcmp(arr[i], arr[i + 1]) > 0)
		{
			arr = ft_split_swap(arr, i, i + 1);
			i = -1;
		}
	}
	return (arr);
}
