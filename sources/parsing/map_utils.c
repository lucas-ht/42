/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:51:27 by troudot           #+#    #+#             */
/*   Updated: 2023/04/13 07:17:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_pos_horizontal(char *str, char del, char from)
{
	int	i;

	i = 0;
	if (from == 'F')
	{
		i = 0;
		while (str[i] && str[i++] == del)
			;
		if (i == (int)ft_strlen(str))
			return (EMPTY_LINE);
	}
	else if (from == 'B')
	{
		i = ft_strlen(str) - 1;
		while (str[i] && str[i--] == del)
			;
		if (i == -1)
			return (EMPTY_LINE);
	}
	return (t(from == 'B', i + 1, t(from == 'F', i - 1, -1)));
}

int	ft_get_pos_vertical(char **arr, int pos_x, char del, char from)
{
	int	i;

	i = 0;
	if (from == 'T')
	{
		i = 0;
		while (i < ft_split_len(arr) && arr[i][pos_x] == del)
			i++;
		if (i == ft_split_len(arr))
			return (EMPTY_LINE);
	}
	else if (from == 'B')
	{
		i = ft_split_len(arr) - 1;
		while (i >= 0 && arr[i][pos_x] == del)
			i--;
		if (i == -1)
			return (EMPTY_LINE);
	}
	return (i);
}

/**
 * The function fills empty cases in a 2D array
 * with spaces to make all rows the same length.
 * 
 * @param arg The parameter "arg" is a pointer to a
 * struct of type "t_arg".
 */
void	ft_fill_empty_case(char **map)
{
	int	big_len;
	int	i;
	int	j;

	i = -1;
	big_len = ft_split_longest(map);
	while (map[++i])
	{
		j = ft_strlen(map[i]);
		while (++j <= big_len)
		{
			map[i] = ft_strjoin_free(map[i], " ");
			if (!map[i])
				ft_error(ERROR_PARSING);
		}
	}
}

bool	ft_split_check_digit(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!map)
		return (ERROR);
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (!ft_strchr(ACCEPT_CHAR, map[i][j]))
				return (false);
		}
		j = -1;
	}
	return (true);
}

t_elem	**ft_char_to_elem(char **map)
{
	int		x;
	int		y;
	t_elem	**elem;

	x = -1;
	y = -1;
	elem = ft_calloc(ft_split_len(map), sizeof(t_elem *));
	while (map[++y])
	{
		elem[y] = ft_calloc(ft_strlen(map[y]), sizeof(t_elem));
		while (map[y][++x])
		{
			if (map[y][x] == ' ')
				elem[y][x] = M_EMPTY;
			else if (map[y][x] == '0')
				elem[y][x] = M_FLOOR;
			else if (map[y][x] == '1')
				elem[y][x] = M_WALL;
			else if (map[y][x] == '2')
				elem[y][x] = M_DOOR;
		}
		x = -1;
	}
	return (ft_free_split(map), elem);
}
