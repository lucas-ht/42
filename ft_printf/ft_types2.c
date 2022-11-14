#include "ft_printf.h"

int	ft_print_arg_pointer(void *p)
{
	ft_putstr_fd("0x", DEFAULT_FILE_DESCRIPTOR);
	return (ft_putpointer_base_fd((unsigned long long) p, "0123456789abcdef",
			DEFAULT_FILE_DESCRIPTOR) + 2);
}

int	ft_print_arg_hex_lowercase(int n)
{
	return (ft_putlong_base_fd((long long) n, "0123456789abcdef",
			DEFAULT_FILE_DESCRIPTOR));
}

int	ft_print_arg_hex_uppercase(int n)
{
	return (ft_putlong_base_fd((long long) n, "0123456789ABCDEF",
			DEFAULT_FILE_DESCRIPTOR));
}
