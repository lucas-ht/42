/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:13:57 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:53:19 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write the integer n to the file descriptor fd
 * 
 * @param n The number to be printed.
 * @param fd The file descriptor of the file to write to.
 */
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
