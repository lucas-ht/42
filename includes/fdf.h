/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:29:30 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/20 07:51:50 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "error.h"

# define MLX_WIDTH			1920
# define MLX_HEIGHT			1080
# define MLX_SIZE			2073600

enum e_color {
	COLOR_TEXT			= 0xffffffff,
	COLOR_UNSPECIFIED	= 0x00000000,
	COLOR_DEFAULT		= 0xffffffff,
	COLOR_RED			= 0xffff0000,
	COLOR_GREEN			= 0xff00ff00,
	COLOR_BLUE			= 0xff0000ff
};

enum e_projection {
	PROJECTION_ISOMETRIC,
	PROJECTION_TOPDOWN
};

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
}	t_point;

typedef struct s_spot
{
	int				z;
	uint32_t		color;
	struct s_spot	*next;
}	t_spot;

typedef struct s_map
{
	int			width;
	int			height;
	int			*z;
	uint32_t	*color;
	t_point		*projection;
}	t_map;

typedef struct s_camera
{
	int			projection;
	int			zoom;
	double		z;
	t_vector3	position;
	t_euler		angle;

	t_vector3	init;
}	t_camera;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;

	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_mlx;

typedef struct s_fdf
{
	t_mlx		*mlx;
	t_map		*map;
	t_camera	*camera;
	uint32_t	color;
	int			redraw;
}	t_fdf;

// parser.c
t_map	*ft_parse(int ac, char **av);

// drawer.c
void	ft_draw(t_fdf *fdf, t_map *map);
void	ft_draw_pixel(t_fdf *fdf, t_point point);

// projection.c
t_point	ft_project(t_fdf *fdf, t_point point);
void	ft_draw_line(t_fdf *fdf, t_point point1, t_point point2);

// map.c
void	ft_point_set(t_point *self, int x, int y, int z);
t_point	ft_point_at(t_map *map, int x, int y);
t_point	ft_point_copy(t_point *point);
int		ft_point_inside(t_point p);

// hook.c
int		ft_hook_key(int key, void *param);

#endif
