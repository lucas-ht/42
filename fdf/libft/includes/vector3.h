/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 03:56:07 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/18 04:12:06 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

typedef struct s_vector3
{
	int		x;
	int		y;
	int		z;
	void	(*set)(struct s_vector3 *self, int x, int y, int z);
}	t_vector3;

t_vector3	ft_vector3_new(int x, int y, int z);
void		ft_vector3_set(t_vector3 *self, int x, int y, int z);
t_vector3	ft_vector3_add(t_vector3 v, t_vector3 w);
t_vector3	ft_vector3_minus(t_vector3 v, t_vector3 w);
int			ft_vector3_dot(t_vector3 v, t_vector3 w);
t_vector3	ft_vector3_multiply(t_vector3 v, int k);
t_vector3	ft_vector3_copy(t_vector3 v);

#endif
