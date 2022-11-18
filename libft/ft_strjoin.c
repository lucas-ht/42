#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (0);
	s = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (s);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy(s + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (s);
}
