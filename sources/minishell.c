/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:13 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/29 01:33:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	g_shell;

static void	ft_welcome(void)
{
	printf("\n𝚖𝚒𝚗𝚒𝚜𝚑𝚎𝚕𝚕 "COLOR_GREY "-" COLOR_RESET);
	printf(" Press ctrl" COLOR_GREY "-" COLOR_RESET "D to exit\n\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(int ac, char **av, char **env)
{
	if ((void) av, ac > 1)
		ft_error(ERROR_ARGV);
	g_shell.running = true;
	g_shell.user = getenv("USER");
	g_shell.path = getcwd(0, 0);
	g_shell.envp = (ft_signal(), init_venv(env), key_toarray(&g_shell.lst_env));
	ft_welcome();
	while (g_shell.running)
	{
		errno = 0;
		ft_prompt();
		ft_debug_leaks();
	}
	exit(ft_atoi(key_get("?", &g_shell.lst_env)->value));
}
