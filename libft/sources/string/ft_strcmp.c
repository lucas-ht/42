/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:00:21 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/31 10:06:16 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_strcmp() compares the two strings s1 and s2. It returns an
 * integer less than, equal
 * to, or greater than zero if s1 is found, respectively, to be less than, to
 * match, or be greater than
 * s2
 * 
 * @param s1 The first string to be compared.
 * @param s2 The string to compare to.
 * 
 * @return The difference between the first two different characters in the
 * strings.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}
