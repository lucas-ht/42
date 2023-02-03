/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 05:16:36 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/14 05:55:41 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_char_to_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

uint64_t	ft_atoi_hex(const char *str)
{
	uint64_t	n;

	n = 0;
	while (ft_strchr(" \n\t\f\v\r", *str))
		str++;
	if (!ft_strncmp(str, "0x", 2))
	{
		str++;
		str++;
	}
	while (*str && ft_strchr("0123456789ABCDEFabcdef", *str))
		n = (n * 0x10) + ft_char_to_hex(*str++);
	return (n);
}
