/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 05:21:59 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/05 05:22:11 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char *str, char *charset)
{
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && ft_strchr(charset, *str))
			str++;
		if (*str)
			c++;
		while (*str && !ft_strchr(charset, *str))
			str++;
	}
	return (c);
}
