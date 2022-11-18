#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	m = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		m = n * -1;
	}
	if (m >= 10)
		ft_putnbr_fd(m / 10, fd);
	ft_putchar_fd(m % 10 + '0', fd);
}
