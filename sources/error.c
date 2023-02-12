/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:54:11 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 07:50:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

#ifdef DEBUG
/**
 * It prints an error message to the standard error output and exits the program
 * 
 * @param error The error message to be displayed.
 */
void	ft_error(char *error)
{
	ft_putendl_fd(error, STDERR_FILENO);
	exit(1);
}
#else

void	ft_error(char *error)
{
	(void) error;
	ft_putendl_fd(ERROR_GENERIC, STDERR_FILENO);
	exit(1);
}
#endif

#ifdef DEBUG
/**
 * It prints an error message to the standard error output and exits the program
 * 
 * @param message The message to be displayed.
 * @param error The error message to be displayed.
 */
void	ft_error_input(char *message, char *error)
{
	ft_putstr_fd(message, STDERR_FILENO);
	if (error)
	{
		ft_putstr_fd(" `", STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
		ft_putendl_fd("`", STDERR_FILENO);
	}
	exit(1);
}
#else

void	ft_error_input(char *message, char *error)
{
	(void) message;
	(void) error;
	ft_putendl_fd(ERROR_GENERIC, STDERR_FILENO);
	exit(1);
}
#endif
