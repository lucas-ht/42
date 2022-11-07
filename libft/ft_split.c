/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:00:58 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/05 19:42:48 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_charset(char c, char charset)
{
	return (c == charset);
}

static int	count_word(char *str, char charset)
{
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && is_char_in_charset(*str, charset))
			str++;
		if (*str)
			c++;
		while (*str && !is_char_in_charset(*str, charset))
			str++;
	}
	return (c);
}

static int	str_len(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_char_in_charset(str[i], charset))
		i++;
	return (i);
}

static char	*ft_split_word(char *str, char charset)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = str_len(str, charset);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static void	list_free(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);-
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**strs;
	int		i;

	if (!s)
		return (0);
	str = (char *) s;
	i = 0;
	strs = malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!strs)
		return (0);
	while (*str)
	{
		while (*str && is_char_in_charset(*str, c))
			str++;
		if (*str)
		{
			strs[i++] = ft_split_word(str, c);
			if (!strs[i - 1])
			{
				list_free(strs, i);
				return (0);
			}
		}
		while (*str && !is_char_in_charset(*str, c))
			str++;
	}
	strs[i] = 0;
	return (strs);
}
