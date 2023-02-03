/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:25:48 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/27 05:45:17 by lucas            ###   ########.fr       */
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

# define ERROR_ARGV					"Wrong number of arguments"
# define ERROR_ARGV_NUM				"Numeric argument required"
# define ERROR_MALLOC				"An error occured while allocating memory"

# define ERROR_PARSING				"A parsing error occured"
# define ERROR_PARSING_INPUT		"A parsing error occured near"
# define ERROR_PARSING_REDIRECTION	"A redirection error occured near"
# define ERROR_PARSING_FILE			"An error occured while opening the file : "
# define ERROR_PARSING_QUOTES		"You must close the quotes"
# define ERROR_PARSING_DOUBLE		"You cannot redirect multiple time"
# define ERROR_PARSING_FINPUT		"You must redirect the input"
# define ERROR_PARSING_FOUTPUT		"You must redirect the output"
# define ERROR_PARSING_DELIMITER	"You must set a delimiter"

# define EXEC_ERROR					1
# define EXEC_SUCCESS				0
# define ERROR_BUILTIN				"An error occured while running a builtin"
# define ERROR_EXPORT				"You must enter a valid variable name"

# define ERROR_PIPE					"An error occured while piping"
# define ERROR_FORK					"An error occured while forking"
# define ERROR_FILE					"An error occured while opening the file"
# define ERROR_EXTERN				"An error occured while running a command"
# define ERROR_UNKNOWN				"Unknown command"
# define ERROR_DIR					"You cannot execute a directory"

void	ft_error(char *error);
void	*ft_warning(char *error);
void	*ft_warning_input(char *message, char *error);
int		ft_warning_exec(char *error);

#endif
