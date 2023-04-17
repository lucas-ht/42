/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 03:56:07 by lhutt             #+#    #+#             */
/*   Updated: 2023/04/16 07:04:14 by lucas            ###   ########.fr       */
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
t_vector3	ft_vector3_normalize(t_vector3 v, double (*sqrt)(double));
t_vector3	ft_euler_normalize(t_vector3 v);
double		ft_vector3_dist(t_vector3 v, t_vector3 w, double (*sqrt)(double));
int			ft_vector3_equal(t_vector3 v, t_vector3 w);

#endif
