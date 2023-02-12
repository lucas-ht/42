/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:54:29 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 07:49:20 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <stdlib.h>

# define ERROR						(void *) -1
# define ERROR_INT					-1

# define ERROR_GENERIC				"Error"
# define ERROR_FATAL				"A fatal error occured"
# define ERROR_ARGV					"Wrong number of arguments"
# define ERROR_ARGV_NUM				"Numeric argument required"
# define ERROR_PARSE				"An error occured while parsing"
# define ERROR_PARSE_VALUE			"Invalid value near"
# define ERROR_PARSE_DUP			"Duplicate value near"
# define ERROR_OP					"Invalid use of operator"
# define ERROR_ACTION				"Invalid use of action"
# define ERROR_CHECKER				"Invalid operator near"

void	ft_error(char *error);
void	ft_error_input(char *message, char *error);
void	ft_debug_warning(char *message, char *error);

#endif