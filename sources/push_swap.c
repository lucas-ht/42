/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 03:44:34 by lucas             #+#    #+#             */
/*   Updated: 2023/02/12 13:48:25 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It parses the arguments, ranks the elements,
 * sorts the elements, and prints the operations
 * 
 * @param ac the number of arguments passed to the program
 * @param av the array of strings passed to the program
 * 
 * @return The return value is the number of elements in the list.
 */
int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = ft_parse(ac, av);
	ft_rank(stacks);
	ft_sorter(stacks);
	ft_op_print(stacks);
	ft_lstclear(&stacks->l[A], free);
	ft_lstclear(&stacks->l[B], free);
	ft_lstclear(&stacks->op, free);
	free(stacks);
	return (0);
}
