/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:33:55 by lucas             #+#    #+#             */
/*   Updated: 2023/04/12 23:34:39 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It counts the number of times a character 
 * from a given set appears in a string
 * 
 * @param str the string to be searched
 * @param charset a string containing all the characters to be counted
 * 
 * @return The number of times a character from charset is found in str.
 */
int	ft_strchr_cnt(char *str, char *charset)
{
	int	i;
	int	res;

	if (!str || !charset)
		return (0);
	i = -1;
	res = 0;
	while (str[++i])
		if (ft_strchr(charset, str[i]))
			res++;
	return (res);
}
