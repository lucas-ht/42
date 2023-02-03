/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:50:23 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/04 23:19:58 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
