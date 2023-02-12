/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:50:36 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/24 13:01:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_copy(char **str)
{
	char	**s;
	int		i;

	if (!str)
		return (0);
	s = (char **) ft_calloc(ft_split_len(str) + 1, sizeof(char *));
	if (!s)
		return (0);
	i = -1;
	while (str[++i])
	{
		s[i] = ft_strdup(str[i]);
		if (!s[i])
			return (ft_split_error(s, i));
	}
	s[i] = 0;
	return (s);
}
