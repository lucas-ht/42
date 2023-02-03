#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	while (s[i] != (unsigned char) c)
		if (!i--)
			return (0);
	return ((char *)(s + i));
}
