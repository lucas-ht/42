/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:16:26 by lucas             #+#    #+#             */
/*   Updated: 2023/03/26 20:56:49 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string and returns a copy of it with all the letters in lowercase
 * 
 * @param s The string to be converted to lowercase.
 * 
 * @return A pointer to a string.
 */
char	*ft_strlower(char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	str = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (*s)
		str[i++] = ft_tolower(*s++);
	str[i] = 0;
	return (str);
}
