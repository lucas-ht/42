#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			*(char *)(dst + len) = *(char *)(src + len);
	else if (src >= dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
