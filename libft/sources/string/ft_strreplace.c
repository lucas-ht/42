/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:10:35 by lucas             #+#    #+#             */
/*   Updated: 2023/02/27 08:41:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strreplace_len(char *s, char *old, char *new)
{
	int	len;
	int	old_len;

	len = ft_strlen(s);
	old_len = ft_strlen(old);
	while (*s)
	{
		if (!ft_strncmp(s, old, old_len))
			len += ft_strlen(new) - old_len;
		s++;
	}
	return (len);
}

/**
 * It replaces all occurrences of a string with another string
 * 
 * @param s The string to be replaced.
 * @param old the string to be replaced
 * @param new the string to replace the old string with
 * 
 * @return A pointer to a string.
 */
char	*ft_strreplace(char *s, char *old, char *new)
{
	char	*str;
	int		old_len;
	int		i;

	if (!s || !old || !*old || !new)
		return (0);
	str = ft_calloc(ft_strreplace_len(s, old, new) + 1, sizeof(char));
	if (!str)
		return (0);
	old_len = ft_strlen(old);
	i = 0;
	while (*s)
	{
		if (!ft_strncmp(s, old, old_len))
		{
			i += ft_strlcpy(&str[i], new, ft_strlen(new) + 1);
			s += old_len * sizeof(char);
		}
		else
			str[i++] = *s++;
	}
	return (str);
}
