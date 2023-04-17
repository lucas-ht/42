/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 03:11:52 by troudot           #+#    #+#             */
/*   Updated: 2023/04/14 10:55:24 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft.h"

# define ERROR						(void *) -1
# define ERROR_INT					-1
# define EMPTY_LINE					-4

# define ERROR_ARGV					"Invalid number of arguments"

# define ERROR_MAP					"The given map is invalid"
# define ERROR_MAP_EXTENSION		"The filename must end with `.cub`"
# define ERROR_MAP_WALLS			"The given map isn't closed"
# define ERROR_MAP_SPAWNS			"Invalid number of spawn points"

# define ERROR_MLX					"An error occured while initializing mlx"
# define ERROR_MLX_IMAGE			"An error occured while creating an image"
# define ERROR_MLX_TEXTURE			"An error occured while loading a texture"

# define ERROR_PARSING				"A parsing error occured"
# define ERROR_PARSING_FILE			"An error occured while opening the file"

# define EXEC_ERROR					1
# define EXEC_SUCCESS				0

void	ft_error(char *error);
void	ft_error_void(char *error);
int		ft_error_int(char *error);
void	*ft_warning(char *error);
void	*ft_warning_input(char *message, char *error);
int		ft_warning_exec(char *error);

#endif