/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:52:49 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 08:03:16 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It checks for duplicate values in the stack
 * 
 * @param stack the stack to check for duplicates
 */
static void	ft_parse_dup(t_list *stack)
{
	int	n;

	n = (int)((t_value *)stack->content)->value;
	while (stack->previous)
	{
		stack = stack->previous;
		if (n == (int)((t_value *)stack->content)->value)
			ft_error_input(ERROR_PARSE_DUP, ft_itoa(n));
	}
}

/**
 * It parses the input and
 * creates a linked list of t_value structs
 * 
 * @param av the string to be parsed
 * 
 * @return A pointer to a list.
 */
static t_list	*ft_parse_next(char *av)
{
	t_list	*list;
	t_value	*value;

	if (!ft_isnumber(av) || !ft_isint(ft_atoi(av)))
		ft_error_input(ERROR_PARSE, av);
	value = (t_value *) ft_calloc(1, sizeof(t_value));
	if (!value)
		ft_error(ERROR_PARSE);
	value->value = (int) ft_atoi(av);
	list = ft_lstnew((void *) value);
	if (!list)
		ft_error(ERROR_PARSE);
	return (list);
}

/**
 * It takes a list of strings and returns a list of strings
 * 
 * @param ac the number of arguments
 * @param av The array of strings passed to the program.
 * 
 * @return a pointer to a pointer to a char.
 */
static char	**ft_parse_convert(int ac, char **av)
{
	if (ac == 2)
		return (ft_split(av[1], " "));
	return (ft_split_copy(&av[1]));
}

/**
 * It takes the arguments from the command line,
 * converts them to integers, checks for duplicates, and
 * puts them in a linked list
 * 
 * @param ac the number of arguments passed to the program
 * @param av the array of strings to be parsed
 * 
 * @return A pointer to a t_stacks struct.
 */
t_stacks	*ft_parse(int ac, char **av)
{
	t_stacks	*stacks;
	t_list		*stack;
	int			i;

	if (ac == 1)
		ft_error(ERROR_ARGV);
	av = ft_parse_convert(ac, (char **) av);
	if (!av)
		ft_error(ERROR_PARSE);
	stack = 0;
	i = -1;
	while (av[++i])
	{
		ft_lstadd_back(&stack, ft_parse_next(av[i]));
		ft_parse_dup(ft_lstlast(stack));
	}
	ft_free_split(av);
	stacks = (t_stacks *) ft_calloc(1, sizeof(t_stacks));
	if (!stacks)
		ft_error(ERROR_PARSE);
	stacks->l[A] = stack;
	stacks->len[A] = ft_lstsize(stack);
	return (stacks);
}
