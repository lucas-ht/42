/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:37:32 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:46:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It joins two strings, and frees the first one
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to s1.
 * 
 * @return A pointer to a string.
 */
char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (s1)
		free((void *) s1);
	return (s);
}
