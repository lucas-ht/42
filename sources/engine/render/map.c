/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:52:15 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 13:42:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*ft_textures(t_cub3d *cub, int index)
{
	if (cub->traces[index].elem == M_DOOR && cub->map->textures->door)
		return (cub->map->textures->door);
	if (cub->traces[index].card == C_NORTH)
		return (cub->map->textures->north);
	if (cub->traces[index].card == C_SOUTH)
		return (cub->map->textures->south);
	if (cub->traces[index].card == C_EAST)
		return (cub->map->textures->east);
	if (cub->traces[index].card == C_WEST)
		return (cub->map->textures->west);
	return (cub->map->textures->north);
}

static u_int32_t	ft_texture(mlx_texture_t *textures, int x, int y)
{
	while (textures->width * 4 < (uint32_t) x)
		x -= textures->width * 4;
	return ((textures->pixels[x + (y * textures->width)] << 24)
		| (textures->pixels[x + 1 + (y * textures->width)] << 16)
		| (textures->pixels[x + 2 + (y * textures->width)] << 8)
		| 0xFF);
}

static void	ft_draw_column(t_cub3d *cub, int index, t_vector3 pos, int wall[2])
{
	int				i;
	mlx_texture_t	*texture;
	int				y[2];

	y[0] = t(HEIGHT / 2 - pos.y / 2 > 0, HEIGHT / 2 - pos.y / 2, 0);
	y[1] = t(pos.y > HEIGHT, HEIGHT, pos.y);
	texture = ft_textures(cub, index);
	i = -1;
	while (++i < y[1])
	{
		mlx_put_pixel(cub->mlx->map, pos.x, y[0] + i,
			ft_texture(texture,
				(wall[0] * texture->width / wall[1]) * 4,
				(i * texture->height / y[1]) * 4));
	}
}

static int	ft_map_height(double distance, int angle)
{
	double	rad;

	rad = ft_angle_rad(angle - PLAYER_FOV / 2 - RAY_TOLERENCE / 2);
	return (HEIGHT * 100 / (distance * cos(rad)));
}

void	ft_render_map(t_cub3d *cub)
{
	int			i;
	int			wall[2];
	t_vector3	pos;
	t_trace		trace;

	ft_mlx_clear(cub->mlx->map);
	i = RAY_TOLERENCE / 2;
	pos.x = -1;
	wall[0] = ft_map_wall_delta(cub, RAY_TOLERENCE / 2);
	trace = cub->traces[RAY_TOLERENCE / 2];
	while (++pos.x < WIDTH)
	{
		if (pos.x % (WIDTH / RAY_NUMBER) == 0
			&& i < RAY_NUMBER - 1 + RAY_TOLERENCE / 2)
			i++;
		if (!ft_vector3_equal(cub->traces[i].pos, trace.pos)
			|| cub->traces[i].card != trace.card)
			wall[0] = ft_map_wall_delta(cub, i);
		pos.y = ft_map_height(cub->traces[i].distance, cub->traces[i].angle.y);
		wall[0]++;
		wall[1] = ft_map_wall_fullsize(cub, i);
		ft_draw_column(cub, i, pos, wall);
		trace = cub->traces[i];
	}
}
