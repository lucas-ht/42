#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (!s1)
		return (0);
	str = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
