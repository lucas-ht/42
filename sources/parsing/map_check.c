/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 07:06:12 by troudot           #+#    #+#             */
/*   Updated: 2023/04/13 07:17:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "cub3d.h"

static bool	ft_check_vertical(char **map, int pos_x)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = ft_get_pos_vertical(map, pos_x, ' ', 'T');
	j = ft_get_pos_vertical(map, pos_x + 1, ' ', 'T');
	k = ft_get_pos_vertical(map, pos_x, ' ', 'B');
	l = ft_get_pos_vertical(map, pos_x + 1, ' ', 'B');
	if ((i == EMPTY_LINE && k == EMPTY_LINE)
		|| (j == EMPTY_LINE && l == EMPTY_LINE))
		return (true);
	while (i < j)
		i++;
	while (j < i)
		j++;
	while (k > l)
		k--;
	while (l > k)
		l--;
	if (map[i][pos_x] == '1' && map[j][pos_x + 1] == '1'
		&& map[k][pos_x] == '1' && map[l][pos_x + 1] == '1')
		return (true);
	return (false);
}

static bool	ft_check_horizontal(char *first, char *second)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = ft_get_pos_horizontal(first, ' ', 'F');
	j = ft_get_pos_horizontal(second, ' ', 'F');
	k = ft_get_pos_horizontal(first, ' ', 'B');
	l = ft_get_pos_horizontal(second, ' ', 'B');
	if ((i == EMPTY_LINE && k == EMPTY_LINE)
		|| (j == EMPTY_LINE && l == EMPTY_LINE))
		return (true);
	while (i < j)
		i++;
	while (j < i)
		j++;
	while (k > l)
		k--;
	while (l > k)
		l--;
	if (first[i] == '1' && second[j] == '1'
		&& first[k] == '1' && second[l] == '1')
		return (true);
	return (false);
}

/**
 * It checks if there's exactly one spawn point in the map
 * 
 * @param arg the structure containing all the information about the map
 * 
 * @return A boolean value.
 */
static bool	ft_check_spawn(char **map)
{
	int	res;
	int	i;

	i = -1;
	res = 0;
	while (map[++i])
		res += ft_strchr_cnt(map[i], "NEWS");
	if (res != 1)
		return (false);
	return (true);
}

void	ft_check_map(t_map *map)
{
	size_t	i;

	i = -1;
	while (map->map_raw[++i + 1])
		if (!ft_check_horizontal(map->map_raw[i], map->map_raw[i + 1]))
			ft_error(ERROR_MAP_SPAWNS);
	i = -1;
	while (++i < ft_split_longest(map->map_raw) - 1)
		if (!ft_check_vertical(map->map_raw, i))
			ft_error(ERROR_MAP_SPAWNS);
	if (!ft_check_spawn(map->map_raw))
		ft_error(ERROR_MAP_SPAWNS);
}
