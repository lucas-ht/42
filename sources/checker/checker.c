/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:20:31 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/07 01:41:00 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**op;
	int			verbose;

	op = ft_reader();
	if (!op || !*op || !ft_isop(op))
	{
		ft_free_split(op);
		ft_printf("Error\n");
		return (0);
	}
	verbose = (ac > 2 && !ft_strncmp(av[1], "-v", 2));
	if (verbose)
	{
		av++;
		ac--;
	}
	stacks.l[a] = ft_parse(ac, av);
	if (!stacks.l[a])
		return (0);
	stacks.len[a] = ft_lstsize2(stacks.l[a]);
	stacks.len[b] = 0;
	ft_checker(&stacks, op, verbose);
	return (0);
}

/*
* Execute the right operation.
*/

void	ft_op(t_stacks *stacks, char *op, int verbose)
{
	if (verbose)
		ft_printf("\033[0;33m");
	if (!ft_strncmp(op, "sa", 3))
		sa(stacks, verbose);
	else if (!ft_strncmp(op, "sb", 3))
		sb(stacks, verbose);
	else if (!ft_strncmp(op, "ss", 3))
		ss(stacks, verbose);
	else if (!ft_strncmp(op, "pa", 3))
		pa(stacks, verbose);
	else if (!ft_strncmp(op, "pb", 3))
		pb(stacks, verbose);
	else if (!ft_strncmp(op, "ra", 3))
		ra(stacks, verbose);
	else if (!ft_strncmp(op, "rb", 3))
		rb(stacks, verbose);
	else if (!ft_strncmp(op, "rr", 3))
		rr(stacks, verbose);
	else if (!ft_strncmp(op, "rra", 3))
		rra(stacks, verbose);
	else if (!ft_strncmp(op, "rrb", 3))
		rrb(stacks, verbose);
	else if (!ft_strncmp(op, "rrr", 3))
		rrr(stacks, verbose);
}

/*
* Execute the operations and checks if the list is sorted.
*/

void	ft_checker(t_stacks *stacks, char **op, int verbose)
{
	while (*op)
	{
		ft_op(stacks, *op++, verbose);
		if (verbose)
		{
			ft_printf("\033[38;5;250m");
			ft_printf("\nStack A (%d) @ %p\n\n",
				stacks->len[a], stacks->l[a]);
			ft_lstprint2(stacks->l[a]);
			ft_printf("\nStack B (%d) @ %p\n\n",
				stacks->len[b], stacks->l[b]);
			ft_lstprint2(stacks->l[b]);
			ft_printf("\033[0m");
		}
	}
	if (ft_is_sorted(stacks))
		ft_printf("\033[0;38;5;190mOK\n");
	else
		ft_printf("\033[0;38;5;196mKO\n");
}
