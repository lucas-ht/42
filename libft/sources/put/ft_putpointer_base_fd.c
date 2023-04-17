/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:26:00 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:53:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putpointer_counter_fd(long long n, char *base, int c, int fd)
{
	unsigned int		base_len;
	unsigned long long	m;

	base_len = ft_strlen(base);
	if (n < 0)
		m = 0xffffffffffffffff + ++n;
	else
		m = n;
	if (m < base_len)
		if (!ft_write_protect(ft_putchar_fd(base[m], fd), &c))
			return (WRITE_ERROR);
	if (m >= base_len)
	{
		if (!ft_write_protect(
				ft_putpointer_counter_fd(m / base_len, base, 0, fd), &c))
			return (WRITE_ERROR);
		if (!ft_write_protect(
				ft_putpointer_counter_fd(m % base_len, base, 0, fd), &c))
			return (WRITE_ERROR);
	}
	return (c);
}

/**
 * It prints a pointer to a file descriptor
 * 
 * @param n the number to be printed
 * @param base the base to convert to
 * @param fd the file descriptor to print to
 * 
 * @return The number of characters printed.
 */
int	ft_putpointer_base_fd(long long n, char *base, int fd)
{
	if (!ft_is_base_valid(base))
		return (0);
	return (ft_putpointer_counter_fd(n, base, 0, fd));
}
