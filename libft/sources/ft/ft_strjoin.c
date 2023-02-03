/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:37:32 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/15 20:30:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 && !s2)
		return (0);
	s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (0);
	if (s1)
		ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	if (!s2)
		return (s);
	if (s2)
		ft_strlcpy(s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s);
}
