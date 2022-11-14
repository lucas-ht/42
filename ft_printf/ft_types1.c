#include "ft_printf.h"

int	ft_print_arg_char(char c)
{
	return (ft_putchar_fd(c, DEFAULT_FILE_DESCRIPTOR));
}

int	ft_print_arg_string(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", DEFAULT_FILE_DESCRIPTOR));
	return (ft_putstr_fd(s, DEFAULT_FILE_DESCRIPTOR));
}

int	ft_print_arg_int(int n)
{
	return (ft_putlong_fd((long) n, DEFAULT_FILE_DESCRIPTOR));
}

int	ft_print_arg_unsigned_int(unsigned int n)
{
	return (ft_putlong_fd(n, DEFAULT_FILE_DESCRIPTOR));
}
