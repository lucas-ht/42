#include "libft.h"

static int	ft_putlong_counter_fd(long n, int c, int fd)
{
	long long	m;

	m = (long long) n;
	if (m < 0)
	{
		if (!ft_write_protect(ft_putchar_fd('-', fd), &c))
			return (WRITE_ERROR);
		m *= -1;
	}
	if (m >= 10)
		if (!ft_write_protect(ft_putlong_counter_fd(m / 10, 0, fd), &c))
			return (WRITE_ERROR);
	if (!ft_write_protect(ft_putchar_fd(m % 10 + '0', fd), &c))
		return (WRITE_ERROR);
	return (c);
}

int	ft_putlong_fd(long n, int fd)
{
	return (ft_putlong_counter_fd(n, 0, fd));
}
