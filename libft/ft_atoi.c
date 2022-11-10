/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:50:23 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/02 20:59:36 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	long	n;

	s = (char *) str;
	sign = 1;
	n = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t'
		|| *s == '\f' || *s == '\v' || *s == '\r')
		s++;
	if (*s == '-')
		sign *= -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		n += (n * 9) + *s++ - '0';
	return ((int) n * sign);
}