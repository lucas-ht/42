/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 04:05:32 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:45:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns the last element of a split string
 * 
 * @param str The string to split.
 * 
 * @return The last element of the array.
 */
char	*ft_split_last(char **str)
{
	if (!str || !*str)
		return (0);
	return (str[ft_split_len(str) - 1]);
}
