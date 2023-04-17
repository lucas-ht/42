/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:20:52 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 13:43:43 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "MLX42.h"
# include "libft.h"
# include "weapons.h"

# define WIDTH						1280
# define HEIGHT						720

# define PLAYER_MOUSE				1
# define PLAYER_SENSITIVITY			0.15
# define PLAYER_FOV					90
# define PLAYER_VELOCITY			10

# define CROSSHAIR_SIZE				20
# define CROSSHAIR_THICKNESS		4
# define CROSSHAIR_GAP				4
# define CROSSHAIR_T				1
# define CROSSHAIR_COLOR			0x00FFFFFF

# define TEXTURE_PATH				"./textures/"
# define TEXTURE_PATH_HUD			"./textures/hud/"

# define MAP_MULTIPIER				100
# define MAP_DOOR_OPEN				10
# define MAP_DOOR_CLOSE				1.5

# define MINIMAP_RENDER 			1
# define MINIMAP_SIZE				500
# define MINIMAP_MAX				10
# define MINIMAP_PLAYER_SIZE		10
# define MINIMAP_RAY_DISTANCE		100
# define MINIMAP_RAY_NUMBER			30

# define RAY_DISTANCE				3000
# define RAY_NUMBER					90
# define RAY_TOLERENCE				20

typedef struct s_player
{
	t_vector3						pos;
	t_vector3						angle;
	t_weapon						weapon;
}	t_player;

typedef struct s_textures
{
	mlx_texture_t					*north;
	mlx_texture_t					*east;
	mlx_texture_t					*west;
	mlx_texture_t					*south;
	mlx_texture_t					*door;
	mlx_texture_t					*sky;
}	t_textures;

typedef struct s_mlx
{
	mlx_t							*mlx;
	int								mouse;
	mlx_image_t						*intro;
	mlx_texture_t					*intro_texture;
	mlx_image_t						*map;
	mlx_image_t						*background;
	mlx_image_t						*background_sky;
	mlx_image_t						*minimap;
	mlx_image_t						*minimap_player;
	mlx_image_t						*weapon;
	mlx_image_t						*hud_fps;
	mlx_image_t						*hud_crosshair;
	mlx_image_t						*hud_ammo;
}	t_mlx;

typedef enum e_elem
{
	M_EMPTY							= 1,
	M_WALL							= 2,
	M_FLOOR							= 3,
	M_DOOR							= 4,
	M_DOOR_OPEN						= 5,
}	t_elem;

typedef enum s_card
{
	C_NORTH							= 1,
	C_EAST							= 2,
	C_SOUTH							= 3,
	C_WEST							= 4,
}	t_card;

typedef struct s_map
{
	char							**map_raw;
	t_elem							**map;
	int								width;
	int								height;
	t_textures						*textures;
	uint32_t						color_ceiling;
	uint32_t						color_floor;
	int								minimap;
}	t_map;

typedef struct s_trace
{
	double							distance;
	t_vector3						angle;
	t_elem							elem;
	t_vector3						vec;
	t_card							card;
	t_vector3						pos;
}	t_trace;

typedef struct s_cub3d
{
	int								loader;
	t_map							*map;
	t_player						*player;
	t_mlx							*mlx;
	t_trace							traces[RAY_NUMBER + RAY_TOLERENCE];
	t_weapon_data					weapons[WEAPON_NUMBER];
}	t_cub3d;

// mlx/mlx.c
void			ft_mlx_clear(mlx_image_t *image);
uint32_t		ft_mlx_color(int r, int g, int b);
t_mlx			*ft_mlx_init(void);
mlx_image_t		*ft_mlx_image(mlx_t *mlx, t_vector3 size, t_vector3 pos, int z);

// mlx/texture.c
mlx_texture_t	*ft_mlx_texture_png(char *path);
mlx_texture_t	**ft_mlx_textures_png(char *path, int count);
mlx_image_t		*ft_mlx_texture_image(mlx_t *mlx, mlx_texture_t *texture,
					t_vector3 pos);

// mlx/loader.c
void			ft_mlx_loader(t_cub3d *cub);

// render/raycasting.c
void			ft_raycasting(t_cub3d *cub);

// render/map.c
void			ft_render_map(t_cub3d *cub);

// render/map_wall/c
int				ft_map_wall_fullsize(t_cub3d *cub, int index);
int				ft_map_wall_shortsize(t_cub3d *cub, int index);
int				ft_map_wall_delta(t_cub3d *cub, int index);

// render/background.c
void			ft_render_background(t_cub3d *cub);

// hud/minimap/minimap.c
void			ft_minimap_render(t_cub3d *cub);

// hud/minimap/player.c
void			ft_minimap_render_player(t_cub3d *cub);

// hud/hud.c
void			ft_hud_init(t_cub3d *cub);
void			ft_hud_draw(t_cub3d *cub);

// hud/fps.c
void			ft_hud_fps(t_cub3d *cub);

// hud/crosshair.c
void			ft_hud_crosshair(t_cub3d *cub);

// hud/ammo.c
void			ft_hud_ammo(t_cub3d *cub);

// hud/intro.c
void			ft_hud_intro(t_mlx	*mlx);

// map.c
void			ft_map_door_open(t_cub3d *cub);
t_elem			ft_map_at(t_cub3d *cub, double x, double y);

// angle.c
double			ft_angle_rad(double angle);
t_vector3		ft_angle_polar(t_vector3 angle, double distance);

// player/movement.c
void			ft_movement_forward(t_cub3d *cub);
void			ft_movement_backward(t_cub3d *cub);
void			ft_movement_right(t_cub3d *cub);
void			ft_movement_left(t_cub3d *cub);

// weapons/init.c
void			ft_weapon_init(t_cub3d *cub);
void			ft_weapon_free(t_cub3d *cub);

// weapons/switch.c
void			ft_weapon_action(t_cub3d *cub, t_weapon_state state);
void			ft_weapon_switch(t_cub3d *cub, unsigned int id);

// weapons/render.c
void			ft_weapon_render(t_cub3d *cub);

// weapons/hud.c
void			ft_weapon_hud(t_cub3d *cub);

// hooks/hook.c
void			ft_hook(t_cub3d *cub);

// hooks/movement.c
void			ft_hook_movement(t_cub3d *cub3d);

// hooks/angle.c
void			ft_hook_angle_key(t_cub3d *cub);
void			ft_hook_angle_mouse(t_cub3d *cub, t_vector3 delta);

#endif