/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 08:50:23 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 09:24:59 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_wall_fullsize(t_cub3d *cub, int index)
{
	t_vector3	current;
	t_card		card;
	int			size;

	size = 0;
	current = cub->traces[index].pos;
	card = cub->traces[index].card;
	while (index > 0
		&& ft_vector3_equal(current, cub->traces[index].pos)
		&& cub->traces[index].card == card)
	{
		current = cub->traces[index].pos;
		card = cub->traces[index].card;
		index--;
	}
	while (index++ < RAY_NUMBER + RAY_TOLERENCE
		&& ft_vector3_equal(current, cub->traces[index].pos)
		&& cub->traces[index].card == card)
	{
		current = cub->traces[index].pos;
		card = cub->traces[index].card;
		size++;
	}
	return (size * (WIDTH / RAY_NUMBER));
}

int	ft_map_wall_shortsize(t_cub3d *cub, int index)
{
	t_vector3	current;
	t_card		card;
	int			size;

	size = 0;
	current = cub->traces[index].pos;
	card = cub->traces[index].card;
	while (index++ < RAY_NUMBER + RAY_TOLERENCE
		&& ft_vector3_equal(current, cub->traces[index].pos)
		&& cub->traces[index].card == card)
	{
		current = cub->traces[index].pos;
		card = cub->traces[index].card;
		size++;
	}
	return (size * (WIDTH / RAY_NUMBER));
}

int	ft_map_wall_delta(t_cub3d *cub, int index)
{
	return (ft_map_wall_fullsize(cub, index)
		- ft_map_wall_shortsize(cub, index));
}
