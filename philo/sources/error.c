/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:58 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 05:39:18 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

/**
 * @brief Shortcut function that print the message and returns.
 * 
 * @param s 
 * @return void* 
 */

void	*ft_error(char *s)
{
	if (s)
		printf("%s\n", s);
	return (0);
}

int	ft_error_int(char *s)
{
	if (s)
		printf("%s\n", s);
	return (0);
}
