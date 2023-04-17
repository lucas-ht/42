/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:54:42 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:45:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * It takes an integer and returns a string representation of that integer
 * 
 * @param n the number to be converted
 * 
 * @return A pointer to the first character of the string.
 */
char	*ft_itoa(int n)
{
	char	*s;
	long	m;
	int		len;

	m = (long) n;
	len = ft_len(m);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	if (m < 0)
		m *= -1;
	s += len;
	*s = 0;
	if (m == 0)
		*--s = '0';
	while (m > 0)
	{
		*--s = m % 10 + '0';
		m /= 10;
	}
	if (n < 0)
		*--s = '-';
	return (s);
}
