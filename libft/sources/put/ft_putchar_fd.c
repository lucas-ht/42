/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 04:09:03 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/26 20:52:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_putchar_fd() writes the character c to the file descriptor fd.
 * 
 * @param c the character to print
 * @param fd file descriptor
 * 
 * @return The number of bytes written.
 */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
