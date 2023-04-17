/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:28:16 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:43:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The function ft_isascii() checks if the passed character is an ASCII character
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is an ASCII character, and 0 if it is not.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
