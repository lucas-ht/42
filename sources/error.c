/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 04:31:40 by lhutt             #+#    #+#             */
/*   Updated: 2023/04/14 10:14:49 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "color.h"

/**
 * It prints an error message to stderr and exits the program
 * 
 * @param error The error message to print.
 */
void	ft_error(char *error)
{
	if (errno == 0)
		ft_putendl_fd(error, 2);
	else
		perror(error);
	exit(1);
}

/**
 * It prints an error message to stderr and returns ERROR
 * 
 * @param error The error message to print.
 * @return a pointer to NULL
 */
void	*ft_warning(char *error)
{
	if (errno == 0)
		ft_putendl_fd(error, 2);
	else
		perror(error);
	return (errno = 0, ERROR);
}

/**
 * It prints an error message to stderr and returns ERROR
 * 
 * @param error The error message to print.
 * 
 * @return a pointer to NULL
 */
void	*ft_warning_input(char *message, char *error)
{
	if (errno != 0)
		return (ft_warning(message));
	(ft_putstr_fd(message, 2), ft_putstr_fd(" `", 2));
	if (error)
		ft_putstr_fd(error, 2);
	return (ft_putendl_fd("`", 2), ERROR);
}

/**
 * It prints an error message to stderr and returns an error code
 * 
 * @param error The error message to print.
 * 
 * @return an error code.
 */
int	ft_warning_exec(char *error)
{
	if (errno == 0)
		ft_putendl_fd(error, 2);
	else
		perror(error);
	return (errno = 0, EXEC_ERROR);
}
