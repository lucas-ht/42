/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:23:47 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:47:23 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string and a function as parameters. It then creates a new string
 * and applies the
 * function to each character of the string.
 * 
 * @param s The string to be mapped.
 * @param f The function to be applied to each character of s.
 * 
 * @return A pointer to a new string.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (!s || !f)
		return (0);
	str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
