/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:47:53 by tim-rdt           #+#    #+#             */
/*   Updated: 2023/04/16 04:38:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_parse_player_position(t_player *player, int x, int y)
{
	player->pos.x = (x + 0.5) * MAP_MULTIPIER;
	player->pos.y = (y + 0.5) * MAP_MULTIPIER;
	player->pos.z = 0;
}

static void	ft_parse_player_angle(t_player *player, char angle)
{
	if (angle == 'N')
		player->angle.y = 270 - PLAYER_FOV / 2;
	if (angle == 'W')
		player->angle.y = 180 - PLAYER_FOV / 2;
	if (angle == 'S')
		player->angle.y = 90 - PLAYER_FOV / 2;
	if (angle == 'E')
		player->angle.y = 360 - PLAYER_FOV / 2;
}

/**
 * The function searches for the starting position and angle of the player
 * in the map.
 * 
 * @param cub a pointer to a struct of type t_cub3d, which contains 
 * information about the game and its state, including the game map.
 * 
 * @return either EXIT_SUCCESS or EXIT_FAILURE depending on whether it
 * was able to find the starting position and angle of the player in the map.
 */
void	ft_parse_player(char **map, t_player *player)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr("NEWS", map[y][x]))
			{
				ft_parse_player_position(player, x, y);
				ft_parse_player_angle(player, map[y][x]);
				map[y][x] = '0';
				return ;
			}
		}
	}
	ft_error(ERROR_MAP_SPAWNS);
}
