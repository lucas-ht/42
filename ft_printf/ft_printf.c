/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:57:05 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/12 03:05:31 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vformat(char c, va_list args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_print_arg_char(va_arg(args, int));
	else if (c == 's')
		n = ft_print_arg_string(va_arg(args, char *));
	else if (c == 'p')
		n = ft_print_arg_pointer(va_arg(args, void *));
	else if (c == 'd')
		n = ft_print_arg_int(va_arg(args, int));
	else if (c == 'i')
		n = ft_print_arg_int(va_arg(args, int));
	else if (c == 'u')
		n = ft_print_arg_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'x')
		n = ft_print_arg_hex_lowercase(va_arg(args, int));
	else if (c == 'X')
		n = ft_print_arg_hex_uppercase(va_arg(args, int));
	else if (c == '%')
		n = ft_print_arg_char('%');
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		c;

	if (!s)
		return (0);
	va_start(args, s);
	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] != '%' || !s[i + 1])
		{
			c += ft_putchar_fd(s[i++], DEFAULT_FILE_DESCRIPTOR);
			continue ;
		}
		c += ft_vformat(s[++i], args);
		i++;
	}
	va_end(args);
	return (c);
}
