/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 07:28:05 by lucas             #+#    #+#             */
/*   Updated: 2023/02/23 07:57:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/**
 * It takes a string and a pointer to a t_stacks struct,
 * and if the string matches one of the
 * operations, it performs that operation on the stacks
 * 
 * @param stacks a pointer to the t_stacks structure
 * @param str the string that is being checked
 */
static void	ft_op(t_stacks *stacks, char *str)
{
	if (!ft_strcmp(str, "sa"))
		return (sa(stacks));
	if (!ft_strcmp(str, "sb"))
		return (sb(stacks));
	if (!ft_strcmp(str, "ss"))
		return (ss(stacks));
	if (!ft_strcmp(str, "pa"))
		return (pa(stacks));
	if (!ft_strcmp(str, "pb"))
		return (pb(stacks));
	if (!ft_strcmp(str, "ra"))
		return (ra(stacks));
	if (!ft_strcmp(str, "rb"))
		return (rb(stacks));
	if (!ft_strcmp(str, "rr"))
		return (rr(stacks));
	if (!ft_strcmp(str, "rra"))
		return (rra(stacks));
	if (!ft_strcmp(str, "rrb"))
		return (rrb(stacks));
	if (!ft_strcmp(str, "rrr"))
		return (rrr(stacks));
	ft_error_input(ERROR_CHECKER, str);
}

/**
 * It reads from stdin,
 * trims the newline, and then calls ft_op() on the trimmed string
 * 
 * @param stacks a pointer to the t_stacks structure
 */
static void	ft_read(t_stacks *stacks)
{
	char		*line;
	char		*trim;

	trim = 0;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		trim = ft_strtrim(line, "\n");
		free(line);
		if (!trim)
			ft_error(ERROR_FATAL);
		if (!*trim)
			break ;
		ft_op(stacks, trim);
		free(trim);
		trim = 0;
		line = get_next_line(STDIN_FILENO);
	}
	if (trim)
		free(trim);
}

/**
 * It parses the arguments, reads the instructions,
 * checks if the stack is sorted, and then frees the
 * memory
 * 
 * @param ac the number of arguments passed to the program
 * @param av the array of strings passed to the program
 */
int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = ft_parse(ac, av);
	ft_read(stacks);
	if (ft_is_sorted(stacks))
		ft_putendl_fd("\033[38;5;190mOK\033[0m", STDOUT_FILENO);
	else
		ft_putendl_fd("\033[38;5;220mKO\033[0m", STDOUT_FILENO);
	ft_lstclear(&stacks->l[A], free);
	ft_lstclear(&stacks->l[B], free);
	ft_lstclear(&stacks->op, free);
	free(stacks);
}
