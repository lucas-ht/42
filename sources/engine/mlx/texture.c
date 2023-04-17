/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:23:00 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 11:03:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*ft_mlx_texture_png(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error(ERROR_MLX_TEXTURE);
	return (texture);
}

mlx_texture_t	**ft_mlx_textures_png(char *path, int count)
{
	mlx_texture_t	**textures;
	int				i;
	char			*p;
	char			*anti_leaks;

	textures = (mlx_texture_t **) ft_calloc(count, sizeof(mlx_texture_t *));
	if (!textures)
		ft_error(ERROR_MLX_TEXTURE);
	i = -1;
	while (++i < count)
	{
		anti_leaks = ft_itoa(i);
		p = ft_strjoin(path, anti_leaks);
		free(anti_leaks);
		if (!p)
			ft_error(ERROR_MLX_TEXTURE);
		p = ft_strjoin_free(p, ".png");
		if (!p)
			ft_error(ERROR_MLX_TEXTURE);
		textures[i] = ft_mlx_texture_png(p);
		free(p);
	}
	return (textures);
}

mlx_image_t	*ft_mlx_texture_image(mlx_t *mlx, mlx_texture_t *texture,
				t_vector3 pos)
{
	mlx_image_t		*image;

	if (!texture)
		return (0);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		ft_error(ERROR_MLX_TEXTURE);
	if (mlx_image_to_window(mlx, image, pos.x, pos.y) < 0)
		ft_error(ERROR_MLX_IMAGE);
	return (image);
}
