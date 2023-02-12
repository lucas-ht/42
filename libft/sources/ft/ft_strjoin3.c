/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 04:51:27 by lucas             #+#    #+#             */
/*   Updated: 2023/01/24 04:51:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*s;
	int		len;

	if (!s1 && !s2 && !s3)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	s = (char *) malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	if (s1)
		ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	if (!s2)
		return (s);
	if (s2)
		ft_strlcpy(s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	if (!s3)
		return (s);
	if (s3)
		ft_strlcpy(s + ft_strlen(s1) + ft_strlen(s2), s3, ft_strlen(s3) + 1);
	return (s);
}
