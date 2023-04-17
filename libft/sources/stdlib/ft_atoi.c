/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:50:23 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:54:05 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string, and returns the number that the string represents
 * 
 * @param str The string to be converted.
 * 
 * @return the number of characters that are printed.
 */
long	ft_atoi(const char *str)
{
	int			sign;
	long long	n;

	sign = 1;
	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		n += (n * 9) + *str++ - '0';
	return ((long) n * sign);
}
