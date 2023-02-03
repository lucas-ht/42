/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:15:45 by lucas             #+#    #+#             */
/*   Updated: 2023/01/30 05:07:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_shell	g_shell;

/**
 * It handles the SIGINT signal, which is sent when the user presses Ctrl+C
 * 
 * @param signum The signal number.
 * @param info a pointer to a siginfo_t structure.
 * @param context This is a pointer to a ucontext_t structure.
 * 
 * @return the number of characters read.
 */
static void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	char	*prompt;

	if ((void) info, (void) context, signum != SIGINT)
		return ;
	rl_replace_line("  ", 0);
	rl_on_new_line();
	rl_redisplay();
	prompt = ft_prompt_print();
	if (!prompt)
		return ;
	printf("\n%s", prompt);
	free(prompt);
}

/**
 * It disables the signals SIGINT and SIGQUIT
 */
void	ft_signal_disable(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

/**
 * It sets up a signal handler for SIGINT and SIGQUIT
 */
void	ft_signal(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_RESTART;
	sigemptyset((sa.sa_sigaction = ft_signal_handler, &sa.sa_mask));
	(sigaddset(&sa.sa_mask, SIGINT), sigaction(SIGINT, &sa, 0));
	(sigaddset(&sa.sa_mask, SIGQUIT), sigaction(SIGQUIT, &sa, 0));
}
