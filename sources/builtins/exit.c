/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:49:37 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/22 18:33:48 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It sets the global variable `g_shell.running`
 * to false, which will cause the main loop to exit
 * 
 * @param params A pointer to a t_cmd struct.
 */
int	ft_exit(t_cmd *params)
{
	int	code;

	if (printf("exit\n"), !params->ac)
		return (g_shell.running = false, EXEC_SUCCESS);
	if (!ft_striter_if(*params->av, ft_isdigit))
		return (g_shell.running = false, printf(ERROR_ARGV_NUM "\n"), 255);
	if (params->ac > 1)
		return (ft_warning_exec(ERROR_ARGV));
	code = ft_atoi(*params->av);
	code = t(code > 255, 255, code);
	code = t(code < 0 && code > -255, 256 + code, code);
	code = t(code < -255, code % 256, code);
	return (g_shell.running = false, code);
}
