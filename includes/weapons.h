/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:51:10 by lucas             #+#    #+#             */
/*   Updated: 2023/04/16 05:30:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_H
# define WEAPONS_H

# include "MLX42.h"
# include "libft.h"

# define WEAPON_NUMBER				2
# define WEAPON_PATH				"./textures/weapons/"

# define W_M4						0
# define W_M4_NAME					"M4"
# define W_M4_AMMO					20
# define W_M4_FIRE					7
# define W_M4_RELOAD				43
# define W_M4_INSPECT				68

# define W_KNIFE					1
# define W_KNIFE_NAME				"Knife"
# define W_KNIFE_AMMO				0
# define W_KNIFE_FIRE				0
# define W_KNIFE_RELOAD				0
# define W_KNIFE_INSPECT			72

typedef enum e_weapon_state
{
	WEAPON_IDLE						= 0,
	WEAPON_FIRE						= 1,
	WEAPON_RELOAD					= 2,
	WEAPON_INSPECT					= 3,
}	t_weapon_state;

typedef struct s_weapon_data
{
	unsigned int					id;
	char							*name;
	unsigned int					ammo_count;
	unsigned int					fire_count;
	unsigned int					reload_count;
	unsigned int					inspect_count;
	mlx_image_t						*hud;
	mlx_texture_t					*hud_selected;
	mlx_texture_t					*hud_unselected;
	mlx_texture_t					*idle;
	mlx_texture_t					**fire;
	mlx_texture_t					**reload;
	mlx_texture_t					**inspect;
}	t_weapon_data;

typedef struct s_weapon
{
	unsigned int					id;
	t_weapon_state					state;
	unsigned int					frame;
	unsigned int					ammo;
	t_weapon_data					*data;
}	t_weapon;

#endif