/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:22:12 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:45:49 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It frees all the strings in the array, then frees the array itself,
 * and returns 0
 * 
 * @param strs the array of strings to be freed
 * @param i the index of the string that failed to be allocated
 * 
 * @return A pointer to a string.
 */
void	*ft_split_error(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
	return (0);
}
