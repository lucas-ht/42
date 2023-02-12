/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:07:55 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/25 03:24:31 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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
