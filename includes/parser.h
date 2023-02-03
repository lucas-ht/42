/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:05:21 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/30 02:47:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

# define SPACES				" \t\n\r\f\v"
# define REDIR				"<>|"
# define REDIR_IN			"<"
# define REDIR_OUT			">"
# define REDIR_NEXT			"|"
# define QUOTES				"\"\'"
# define QUOTES_SINGLE		'\''
# define SPECIAL			"$"

typedef enum s_iotype {
	IO_NONE					= 0b00000001,
	IO_IN					= 0b00001110,
	IO_IFILE				= 0b00000010,
	IO_DEL					= 0b00000100,
	IO_PREV					= 0b00001000,
	IO_OUT					= 0b01110000,
	IO_OFILE				= 0b00010000,
	IO_APP					= 0b00100000,
	IO_NEXT					= 0b01000000,
	IO_ERR					= 0b10000000,
	IO_INV					= 0b10000000,
}	t_iotype;

typedef struct s_input {
	t_iotype				type[2];
	char					*file;
}	t_input;

typedef struct s_output {
	t_iotype				type[2];
	char					*file;
}	t_output;

typedef struct s_cmd {
	char					*cmd;
	int						ac;
	char					**av;
	t_input					in;
	t_output				out;
}	t_cmd;

// parser.c
t_list		*ft_parse(char *line);

// cmd.c
t_cmd		*ft_cmd(char *str, t_list *p);
void		ft_cmd_free(void *c);

// split/cmds.c
char		**ft_split_cmds(char *line);

// split/args.c
char		**ft_split_args(char *str);

// special.c
void		*ft_special(t_cmd *cmd);
char		*ft_special_tilde(char *line);

// flags.c
bool		ft_is_flags(t_iotype flag, int flags);
char		*ft_flags_str(t_iotype flag);
t_iotype	ft_flags(char *flag);

// quotes.c
char		ft_parse_quote(char *line, char *p);
char		*ft_quotes(char	*line);

// loop.c
void		*ft_loop(t_cmd *cmd, t_cmd *prev);

// prev.c
bool		ft_prev(char **av, t_cmd *prev);

// error.c
void		*ft_parse_error(t_cmd *cmd, t_cmd *next, t_cmd *prev);

#endif
