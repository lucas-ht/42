/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:16:04 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:44:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns 1 if the character is a whitespace character, and 0 otherwise
 * 
 * @param c The character to be checked.
 * 
 * @return a non-zero value if the character is a white space.
 */
int	ft_iswhite(int c)
{
	return (!!ft_strchr(" \t\n\r\f\v", c));
}
