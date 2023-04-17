/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:40:20 by troudot           #+#    #+#             */
/*   Updated: 2023/04/16 12:47:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_exit(t_cub3d *cub)
{
	int		i;

	free(cub->player);
	i = -1;
	while (++i < cub->map->height)
		free(cub->map->map[i]);
	free(cub->map->map);
	free(cub->map->map_raw);
	mlx_delete_texture(cub->map->textures->north);
	mlx_delete_texture(cub->map->textures->east);
	mlx_delete_texture(cub->map->textures->west);
	mlx_delete_texture(cub->map->textures->south);
	if (cub->map->textures->door)
		mlx_delete_texture(cub->map->textures->door);
	if (cub->map->textures->sky)
		mlx_delete_texture(cub->map->textures->sky);
	free(cub->map);
	free(cub->mlx);
	ft_weapon_free(cub);
}

int	main(int ac, char **av)
{
	t_cub3d	cub;

	errno = 0;
	if (ac != 2)
		ft_error(ERROR_ARGV);
	cub.player = ft_calloc(1, sizeof(t_player));
	if (!cub.player)
		ft_error(ERROR_PARSING);
	cub.map = ft_parsing(cub.player, av[1]);
	cub.mlx = ft_mlx_init();
	cub.loader = -10;
	ft_hook(&cub);
	mlx_loop(cub.mlx->mlx);
	mlx_terminate(cub.mlx->mlx);
	return (EXIT_SUCCESS);
}
