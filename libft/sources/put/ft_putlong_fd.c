/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:10:18 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:53:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * It writes the long integer `n` to the file descriptor `fd`
 * 
 * @param n The number to be printed.
 * @param fd The file descriptor to write to.
 * 
 * @return The number of characters printed.
 */
int	ft_putlong_fd(long n, int fd)
{
	return (ft_putlong_counter_fd(n, 0, fd));
}
