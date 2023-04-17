/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:25:15 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 03:34:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*ft_mlx_image(mlx_t *mlx, t_vector3 size, t_vector3 pos, int z)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, size.x, size.y);
	if (!image)
		ft_error(ERROR_MLX_IMAGE);
	if (mlx_image_to_window(mlx, image, pos.x, pos.y) < 0)
		ft_error(ERROR_MLX_IMAGE);
	mlx_set_instance_depth(image->instances, z);
	return (image);
}

t_mlx	*ft_mlx_init(void)
{
	t_mlx	*mlx;

	mlx = ft_calloc(1, sizeof(t_mlx));
	if (!mlx)
		ft_error(ERROR_MLX);
	mlx->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!mlx->mlx)
		ft_error(ERROR_MLX);
	mlx->background = ft_mlx_image(mlx->mlx, (t_vector3)
		{WIDTH, HEIGHT, 0, 0}, (t_vector3){0, 0, 0, 0}, 1);
	mlx->map = ft_mlx_image(mlx->mlx, (t_vector3)
		{WIDTH, HEIGHT, 0, 0}, (t_vector3){0, 0, 0, 0}, 2);
	mlx->minimap = ft_mlx_image(mlx->mlx, (t_vector3)
		{MINIMAP_SIZE, MINIMAP_SIZE, 0, 0}, (t_vector3){0, 0, 0, 0}, 4);
	mlx->minimap_player = ft_mlx_image(mlx->mlx, (t_vector3)
		{MINIMAP_SIZE, MINIMAP_SIZE, 0, 0}, (t_vector3){0, 0, 0, 0}, 5);
	mlx->hud_crosshair = ft_mlx_image(mlx->mlx, (t_vector3)
		{CROSSHAIR_SIZE, CROSSHAIR_SIZE, 0, 0}, (t_vector3){WIDTH / 2
			- CROSSHAIR_SIZE / 2, HEIGHT / 2 - CROSSHAIR_SIZE / 2, 0, 0}, 11);
	ft_hud_intro(mlx);
	return (mlx);
}

void	ft_mlx_clear(mlx_image_t *image)
{
	ft_bzero(image->pixels, image->width * image->height * sizeof(int32_t));
}

uint32_t	ft_mlx_color(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
