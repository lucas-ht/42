#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
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

char	*ft_strjoin(char *str, char *buffer)
{
	size_t	i;
	char	*s;

	if (!str)
	{
		str = (char *) malloc(1 * sizeof(char));
		str[0] = 0;
	}
	if (!str || !buffer)
		return (0);
	s = (char *) malloc((ft_strlen(str) + ft_strlen(buffer) + 1)
			* sizeof(char));
	if (!s)
		return (0);
	i = -1;
	while (str[++i])
		s[i] = str[i];
	while (*buffer)
		s[i++] = *buffer++;
	s[i] = 0;
	free(str);
	return (s);
}

char	*ft_copy_str(char *str)
{
	char	*s;
	int		i;

	if (!*str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = (char *) malloc(++i * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (*str && *str != '\n')
		s[i++] = *str++;
	if (*str == '\n')
		s[i++] = '\n';
	s[i] = 0;
	return (s);
}

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	s = (char *) malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!s)
		return (0);
	j = 0;
	while (str[++i])
		s[j++] = str[i];
	s[j] = 0;
	free(str);
	return (s);
}
