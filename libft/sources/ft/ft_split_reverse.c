/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:42:12 by lucas             #+#    #+#             */
/*   Updated: 2023/01/24 13:03:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_split_reverse_free(char **strs, int i)
{
	while (strs[++i])
		free(strs[i]);
	free(strs);
	return (0);
}

char	**ft_split_reverse(char **strs)
{
	char	**s;
	int		i;

	i = ft_split_len(strs);
	s = (char **) ft_calloc(i + 1, sizeof(char **));
	if (!s)
		return (0);
	s[i] = 0;
	while (--i >= 0)
	{
		s[i] = ft_strdup(*strs++);
		if (!s[i])
			ft_split_reverse_free(s, i);
	}
	return (s);
}
