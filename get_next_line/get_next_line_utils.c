/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:36:18 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/07 02:49:24 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (0);
	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (s1)
			*s1 = 0;
	}
	while (++i != -1 && s1 && s1[i])
		s[i] = s1[i];
	while (++j != -1 && s2[j])
		s[i + j] = s2[j];
	s[i + j] = 0;
	if (s1)
		free(s1);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;

	if (!s)
		return (0);
	str = (unsigned char *) s;
	while (*str != (unsigned char) c)
	{
		if (!*str++ && c)
			return (0);
	}
	return ((char *) str);
}
