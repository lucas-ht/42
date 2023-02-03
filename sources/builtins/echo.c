/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:45:47 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 03:00:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It prints the arguments passed to it,
 * separated by spaces, and optionally a newline at the end
 * 
 * @param params A pointer to a t_cmd struct.
 */
int	ft_echo(t_cmd *params)
{
	int		i;
	bool	nl;

	nl = true;
	i = 0;
	while (params->av[i] && !ft_strncmp(params->av[i], "-n",
			ft_strlen(params->av[i])) && ++i)
		nl = false;
	while (params->av[i])
	{
		printf("%s", params->av[i++]);
		if (params->av[i])
			printf(" ");
	}
	if (nl)
		printf("\n");
	return (EXEC_SUCCESS);
}
