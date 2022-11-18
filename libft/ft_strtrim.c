/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:50:13 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/18 08:05:35 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len;
	char			*start;
	char			*end;
	char			*str;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_char_in_set(*s1, set))
		s1++;
	start = (char *) s1;
	end = (char *) s1 + (ft_strlen(s1) - 1) * sizeof(char);
	while (end != start && ft_char_in_set(*end, set))
		end--;
	len = end - start + 2;
	if (end == start)
		len = 2;
	str = malloc(len * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, start, len);
	return (str);
}
