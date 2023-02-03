/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_protect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 02:47:27 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/23 01:37:36 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_protect(int ft_put_result, int *c)
{
	if (ft_put_result == WRITE_ERROR)
		return (0);
	*c += ft_put_result;
	return (1);
}
