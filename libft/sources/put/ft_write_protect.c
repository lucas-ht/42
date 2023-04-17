/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_protect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:47:27 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:53:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function is a wrapper for ft_putchar that returns 0 if there is an error,
 * and increments the
 * character count if there is not
 * 
 * @param ft_put_result the result of the ft_putchar function
 * @param c the number of characters printed
 * 
 * @return The number of characters written.
 */
int	ft_write_protect(int ft_put_result, int *c)
{
	if (ft_put_result == WRITE_ERROR)
		return (0);
	*c += ft_put_result;
	return (1);
}
