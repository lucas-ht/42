/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:31:15 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:43:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns 1 if the string is a number, 0 otherwise
 * 
 * @param s The string to check.
 */
int	ft_isnumber(char *s)
{
	if (!s)
		return (0);
	if (*s == '-')
		s++;
	return (*s && ft_striter_if(s, ft_isdigit));
}
