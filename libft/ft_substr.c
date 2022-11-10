/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:33:28 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/05 18:44:35 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
	{
		len = 0;
		start = ft_strlen(s);
	}
	str = (char *) ft_calloc(sizeof(*s), len + 1);
	if (!str)
		return (0);
	i = 0;		
	while (s[start] && i < len)
		str[i++] = s[start++];
	return (str);
}
