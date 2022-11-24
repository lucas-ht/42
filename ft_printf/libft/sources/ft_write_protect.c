#include "../libft.h"

int	ft_write_protect(int ft_put_result, int *c)
{
	if (ft_put_result == WRITE_ERROR)
		return (0);
	*c += ft_put_result;
	return (1);
}
