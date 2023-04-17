/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:26:00 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:52:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putlong_base_counter_fd(long long n, char *base, int c, int fd)
{
	unsigned int		base_len;
	unsigned long long	m;

	base_len = ft_strlen(base);
	if (n < 0)
		m = 0x100000000 + n;
	else
		m = n;
	if (m < base_len)
		if (!ft_write_protect(ft_putchar_fd(base[m], fd), &c))
			return (WRITE_ERROR);
	if (m >= base_len)
	{
		if (!ft_write_protect(
				ft_putlong_base_counter_fd(m / base_len, base, 0, fd), &c))
			return (WRITE_ERROR);
		if (!ft_write_protect(
				ft_putlong_base_counter_fd(m % base_len, base, 0, fd), &c))
			return (WRITE_ERROR);
	}
	return (c);
}

/**
 * It prints a long long number in a given base to a given file descriptor
 * 
 * @param n the number to be converted
 * @param base the base to convert to
 * @param fd the file descriptor to write to
 * 
 * @return The number of characters printed.
 */
int	ft_putlong_base_fd(long long n, char *base, int fd)
{
	if (!ft_is_base_valid(base))
		return (0);
	return (ft_putlong_base_counter_fd(n, base, 0, fd));
}
