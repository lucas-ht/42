/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:24:50 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 06:56:01 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

static void	ft_hook_move(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->camera->position.y += 10;
	if (key == KEY_S)
		fdf->camera->position.y -= 10;
	if (key == KEY_D)
		fdf->camera->position.x -= 10;
	if (key == KEY_A)
		fdf->camera->position.x += 10;
	if (key == KEY_NUMPAD_PLUS)
		fdf->camera->zoom += 1;
	if (key == KEY_NUMPAD_MINUS && fdf->camera->zoom > 1)
		fdf->camera->zoom -= 1;
	if (key == KEY_ARROW_UP && fdf->camera->z > .5)
		fdf->camera->z -= .1;
	if (key == KEY_ARROW_DOWN && fdf->camera->z < 10)
		fdf->camera->z += .1;
}

static void	ft_hook_color(int key, t_fdf *fdf)
{
	(void) key;
	if (fdf->color == COLOR_DEFAULT)
		fdf->color = COLOR_RED;
	else if (fdf->color == COLOR_RED)
		fdf->color = COLOR_GREEN;
	else if (fdf->color == COLOR_GREEN)
		fdf->color = COLOR_BLUE;
	else if (fdf->color == COLOR_BLUE)
		fdf->color = COLOR_DEFAULT;
}

static void	ft_hook_rotate(int key, t_fdf *fdf)
{
	if (key == KEY_NUMPAD_4)
		fdf->camera->angle.z += .1;
	if (key == KEY_NUMPAD_6)
		fdf->camera->angle.z -= .1;
}

static void	ft_hook_projection(int key, t_fdf *fdf)
{
	(void) key;
	fdf->camera->angle = ft_euler_new(0, 0, 0);
	if (fdf->camera->projection == PROJECTION_ISOMETRIC)
		fdf->camera->projection = PROJECTION_TOPDOWN;
	else
		fdf->camera->projection = PROJECTION_ISOMETRIC;
}

int	ft_hook_key(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) param;
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_P)
		ft_hook_projection(key, fdf);
	if (key == KEY_C)
		ft_hook_color(key, fdf);
	if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A
		|| key == KEY_NUMPAD_PLUS || key == KEY_NUMPAD_MINUS
		|| key == KEY_ARROW_UP || key == KEY_ARROW_DOWN)
		ft_hook_move(key, fdf);
	if (key == KEY_NUMPAD_0 || key == KEY_NUMPAD_1
		|| key == KEY_NUMPAD_2 || key == KEY_NUMPAD_3
		|| key == KEY_NUMPAD_4 || key == KEY_NUMPAD_5
		|| key == KEY_NUMPAD_6 || key == KEY_NUMPAD_7
		|| key == KEY_NUMPAD_8 || key == KEY_NUMPAD_9)
		ft_hook_rotate(key, fdf);
	ft_draw(fdf, fdf->map);
	return (0);
}
