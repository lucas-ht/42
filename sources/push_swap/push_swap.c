/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:18:56 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/04 22:41:05 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.l[a] = ft_parse(ac, av);
	if (!stacks.l[a])
		return (0);
	stacks.len[a] = ft_lstsize2(stacks.l[a]);
	stacks.len[b] = 0;
	ft_sorter(&stacks);
	return (0);
}
