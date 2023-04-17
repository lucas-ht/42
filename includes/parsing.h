/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:53:13 by troudot           #+#    #+#             */
/*   Updated: 2023/04/16 04:39:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include "libft.h"
# include "error.h"
# include "engine.h"

# define ACCEPT_CHAR					"012 ENSW\n"

// parsing.c
t_map	*ft_parsing(t_player *player, char *av);
void	ft_check_map(t_map *map);

// texture.c
void	ft_parse_texture(t_map *map);

int		ft_get_pos_horizontal(char *str, char del, char from);
int		ft_get_pos_vertical(char **arr, int pos_x, char del, char from);
void	ft_fill_empty_case(char **map);
bool	ft_split_check_digit(char **map);

// player.c
void	ft_parse_player(char **map, t_player *player);

// utils.c
t_elem	**ft_char_to_elem(char **map);

#endif