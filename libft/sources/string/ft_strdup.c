/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:07:13 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:56:19 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string and returns a copy of it
 * 
 * @param s1 The string to be copied.
 * 
 * @return A pointer to a new string which is a duplicate of the string s1.
 */
char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (0);
	str = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
