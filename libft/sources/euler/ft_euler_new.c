/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_euler_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 04:45:26 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/18 10:45:18 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_euler	ft_euler_new(double x, double y, double z)
{
	t_euler	e;

	e.set = ft_euler_set;
	e.set(&e, x, y, z);
	return (e);
}
