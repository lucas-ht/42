/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:27:12 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 07:24:43 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_hook_terminate(void *param)
{
	(void) param;
	exit(0);
}

static void	ft_init_mlx(t_fdf *fdf)
{
	fdf->mlx = (t_mlx *) ft_calloc(1, sizeof(t_mlx));
	if (!fdf->mlx)
		ft_error(ERROR_MALLOC);
	fdf->mlx->mlx = mlx_init();
	if (!fdf->mlx->mlx)
		ft_error(ERROR_MLX);
	fdf->mlx->win = mlx_new_window(fdf->mlx->mlx, MLX_WIDTH, MLX_HEIGHT, "fdf");
	if (!fdf->mlx->win)
		ft_error(ERROR_MLX);
	fdf->mlx->img = mlx_new_image(fdf->mlx->mlx, MLX_WIDTH, MLX_HEIGHT);
	if (!fdf->mlx->img)
		ft_error(ERROR_MLX);
	fdf->mlx->data_addr = mlx_get_data_addr(fdf->mlx->img,
			&(fdf->mlx->bits_per_pixel), &(fdf->mlx->size_line),
			&(fdf->mlx->endian));
	mlx_hook(fdf->mlx->win, 17, 0, ft_hook_terminate, 0);
	mlx_hook(fdf->mlx->win, 2, 0, ft_hook_key, (void *) fdf);
	ft_draw(fdf, fdf->map);
	mlx_loop(fdf->mlx->mlx);
}

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	errno = 0;
	fdf = (t_fdf *) ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		ft_error(ERROR_MALLOC);
	fdf->map = ft_parse(ac, av);
	fdf->camera = (t_camera *) ft_calloc(1, sizeof(t_camera));
	if (!fdf->camera)
		ft_error(ERROR_MALLOC);
	fdf->camera->projection = PROJECTION_ISOMETRIC;
	fdf->camera->zoom = min(MLX_WIDTH / fdf->map->width / 2,
			MLX_HEIGHT / fdf->map->height / 2);
	fdf->camera->z = 10;
	ft_vector3_set(&fdf->camera->position, 0, 0, 10);
	ft_euler_set(&fdf->camera->angle, 0, 0, 0);
	ft_vector3_set(&fdf->camera->init, INT_MAX, INT_MIN, 1);
	fdf->color = COLOR_DEFAULT;
	ft_init_mlx(fdf);
	free(fdf->camera);
	free(fdf->map->z);
	free(fdf->map->color);
	free(fdf->map);
}
