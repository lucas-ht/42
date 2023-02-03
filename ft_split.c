#include "libft.h"

static int	count_word(char *str, char charset)
{
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && *str == charset)
			str++;
		if (*str)
			c++;
		while (*str && *str != charset)
			str++;
	}
	return (c);
}

static int	ft_split_word(char **strs, char *str, char charset)
{
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != charset)
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

static void	*list_free(char **strs, int i)
{
	while (--i >= 0)
		free(strs[i]);
	free(strs);
	return (0);
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
	strs = malloc((count_word(str, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && !ft_split_word(&strs[i++], str, c))
			return (list_free(strs, i));
		while (*str && *str != c)
			str++;
	}
	strs[i] = 0;
	return (strs);
}
