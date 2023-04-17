/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 05:21:59 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:45:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It counts the number of words in a string
 * 
 * @param str the string to be split
 * @param charset the characters that will be used to split the string
 * 
 * @return The number of words in the string.
 */
int	ft_count(char *str, char *charset)
{
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str)
			c++;
		while (*str && !ft_strchr(charset, *str))
			str++;
	}
	return (c);
}
