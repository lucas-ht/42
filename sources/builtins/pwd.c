/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:47:11 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/22 18:33:48 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It prints the current working directory
 * 
 * @param params a pointer to a t_cmd struct
 */
int	ft_pwd(t_cmd *params)
{
	char		*cwd;

	if (params->ac)
		return (ft_warning_exec(ERROR_ARGV));
	cwd = getcwd(0, 0);
	if (!cwd)
		return (ft_warning_exec(ERROR_BUILTIN));
	return (printf("%s\n", cwd), free(cwd), EXEC_SUCCESS);
}
