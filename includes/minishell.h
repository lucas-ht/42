/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:14:48 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:35:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "libft.h"
# include "error.h"
# include "parser.h"
# include "debug.h"
# include "color.h"
# include "env.h"
# include "process.h"

# define PROMPT_INPUT			"»"

// A struct that contains the shell's name, user, host, and path.
typedef struct s_shell
{
	bool	running;
	char	*user;
	char	*path;
	char	**envp;
	t_list	*lst_env;
}	t_shell;

// prompt.c
void	ft_prompt(void);
char	*ft_prompt_print(void);

// signal.c
void	ft_signal(void);
void	ft_signal_disable(void);

// builtins/*.c
int		ft_echo(t_cmd *params);
int		ft_cd(t_cmd *params);
int		ft_pwd(t_cmd *params);
int		ft_export(t_cmd *params);
int		ft_unset(t_cmd *params);
int		ft_env(t_cmd *params);
int		ft_env_export(t_cmd *params);
int		ft_exit(t_cmd *params);

#endif
