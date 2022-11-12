/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:26:00 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/12 03:45:58 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int	is_base_valid(char *base)
{
	size_t	i;
	size_t	j;
	size_t	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len == 0 || base_len == 1)
		return (0);
	while (base[i])
	{
		if (base[i] <= 32 || base[i] >= 127 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < ft_strlen(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putlong_base_fd(int n, char *base, int fd)
{
	int			base_len;
	long long	m;
	static int	t;

	base_len = ft_strlen(base);
	m = n;
	if (!is_base_valid(base))
		return (t);
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m = -m;
		t++;
	}
	if (m < base_len)
	{
		ft_putchar_fd(base[m], fd);
		t++;
	}
	if (m >= base_len)
	{
		ft_putlong_base_fd(m / base_len, base, fd);
		ft_putlong_base_fd(m % base_len, base, fd);
	}
	return (t);
}
