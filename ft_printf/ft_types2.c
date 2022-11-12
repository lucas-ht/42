/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:07:55 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/12 03:45:13 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg_pointer(void *p)
{
	ft_putstr_fd("0x10", DEFAULT_FILE_DESCRIPTOR);
	return (ft_putlong_base_fd((unsigned) p, "0123456789abcdef", DEFAULT_FILE_DESCRIPTOR) + 4);
}

int	ft_print_arg_hex_lowercase(int n)
{
	return (ft_putlong_base_fd(n, "0123456789abcdef", DEFAULT_FILE_DESCRIPTOR));
}

int	ft_print_arg_hex_uppercase(int n)
{
	return (ft_putlong_base_fd(n, "0123456789ABCDEF", DEFAULT_FILE_DESCRIPTOR));
}
