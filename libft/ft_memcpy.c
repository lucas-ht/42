#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dst && !src)
		return (0);
	d = (char *) dst;
	s = (char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
