/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:00:58 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/08 18:23:25 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_word(char **strs, char *str, char *charset)
{
	int		len;
	int		i;

	len = 0;
	while (str[len] && !ft_strchr(charset, str[len]))
		len++;
	*strs = malloc(sizeof(char) * (len + 1));
	if (!*strs)
		return (0);
	i = -1;
	while (++i < len)
		strs[0][i] = str[i];
	strs[0][i] = 0;
	return (1);
}

char	**ft_split(char const *s, char *charset)
{
	char	*str;
	char	**strs;
	int		i;

	if (!s)
		return (0);
	str = (char *) s;
	i = 0;
	strs = malloc((ft_count(str, charset) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str && !ft_split_word(&strs[i++], str, charset))
			return (ft_split_error(strs, i));
		while (*str && !ft_strchr(charset, *str))
			str++;
	}
	strs[i] = 0;
	return (strs);
}
