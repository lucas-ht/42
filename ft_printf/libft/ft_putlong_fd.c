/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:10:18 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/12 03:13:28 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlong_fd(long n, int fd)
{
	long long		m;
	static int		t;

	m = n;
	t++;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
		t++;
	}
	if (m >= 10)
		ft_putlong_fd(m / 10, fd);
	ft_putchar_fd(m % 10 + '0', fd);
	return (t);
}
