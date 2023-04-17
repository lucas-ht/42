/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:22:46 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:43:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It checks if the character is a digit.
 * 
 * @param c The character to be checked.
 * 
 * @return a non-zero value if the character is a digit, and zero if it is not.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
