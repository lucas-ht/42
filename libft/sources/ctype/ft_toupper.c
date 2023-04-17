/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:42:52 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:44:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the character is lowercase, subtract 32 from it
 * 
 * @param c The character to be converted.
 * 
 * @return the uppercase equivalent of the character passed as an argument,
 * if the argument is a lowercase letter.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}
