/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 05:07:10 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/18 10:44:41 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EULER_H
# define EULER_H

typedef struct s_euler
{
	double	x;
	double	y;
	double	z;
	void	(*set)(struct s_euler *self, double x, double y, double z);
}	t_euler;

t_euler	ft_euler_new(double x, double y, double z);
void	ft_euler_set(t_euler *self, double x, double y, double z);

#endif
