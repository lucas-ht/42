/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:34:07 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:46:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It prints the name of the array, then prints each element of the array,
 * along with its index
 * 
 * @param name The name of the array.
 * @param strs The array of strings to be printed.
 */
void	ft_split_print(char *name, char **strs)
{
	int	i;

	i = -1;
	printf("%s\n", name);
	while (strs[++i])
		printf("%s[%d] = %s\n", name, i, strs[i]);
}
