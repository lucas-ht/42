/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:25:29 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 13:56:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

#ifdef DEBUG

/**
 * It prints the contents of a stack
 * 
 * @param stacks the t_stacks structure
 * @param i the index of the stack to print
 */
void	ft_stack_print(t_stacks *stacks, int i)
{
	t_list	*stack;
	t_value	*value;
	int		j;

	stack = stacks->l[i];
	j = -1;
	while (stack && ++j >= 0)
	{
		value = (t_value *) stack->content;
		ft_printf("stacks[%c] @ %d\t", 'A' + i, j);
		ft_printf("chunk: %d;\trank: %d;\tvalue: %d;\n",
			value->chunk, value->rank, value->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
#else

void	ft_stack_print(t_stacks *stacks, int i)
{
	(void) stacks;
	(void) i;
}
#endif

#ifdef DEBUG

/**
 * It prints a message to the standard error output
 * 
 * @param message The message to be displayed.
 * @param error The error message to be displayed.
 */
void	ft_debug_warning(char *message, char *error)
{
	(ft_putstr_fd(message, 2), ft_putstr_fd(" `", 2));
	if (error)
		ft_putstr_fd(error, 2);
	ft_putendl_fd("`", 2);
}
#else

void	ft_debug_warning(char *message, char *error)
{
	(void) message;
	(void) error;
}
#endif
