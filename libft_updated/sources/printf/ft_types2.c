/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:07:55 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/25 03:24:33 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_arg_pointer(void *p)
{
	int	c;

	c = 0;
	if (!ft_write_protect(ft_putstr_fd("0x", DEFAULT_FILE_DESCRIPTOR), &c))
		return (WRITE_ERROR);
	if (!ft_write_protect(ft_putpointer_base_fd((unsigned long long) p,
				"0123456789abcdef", DEFAULT_FILE_DESCRIPTOR), &c))
		return (WRITE_ERROR);
	return (c);
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
