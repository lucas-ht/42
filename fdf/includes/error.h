/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:25:48 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/18 07:50:34 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <errno.h>

# define ERROR_MALLOC		"An error occured while allocating memory"

# define ERROR_PARSE	 	"An error occured while parsing the map"
# define ERROR_PARSE_ARGS	"Usage: ./fdf [map.fdf]"
# define ERROR_PARSE_NAME 	"The map's name must end with \".fdf\""
# define ERROR_PARSE_OPEN 	"An error occured while trying to open the map"
# define ERROR_PARSE_RECT	"The map must be a rectangle"
# define ERROR_PARSE_SIZE	"The map is too small"

# define ERROR_MLX			"An error occured while using the MLX"

void	ft_error(char *error);

#endif
