#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	n;

	sign = 1;
	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		n += (n * 9) + *str++ - '0';
	return ((int) n * sign);
}
