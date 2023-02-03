/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:20:23 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 02:15:25 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
* Checks for duplicate.
*/

int	ft_parse_is_dup(t_list2 *stack)
{
	int	n;

	if (!stack || !stack->content)
		return (0);
	n = *(int *) stack->content;
	while (stack->previous)
	{
		stack = stack->previous;
		if (n == *(int *)stack->content)
			return (1);
	}
	return (0);
}

/*
* Create a new list if the current input is correct.
*/

t_list2	*ft_parse_next(char *s)
{
	t_list2	*n;
	int		*content;

	if (!ft_isnumber(s) || !ft_isint(ft_atoi(s)))
		return (0);
	content = (int *) malloc(sizeof(int));
	if (!content)
		return (0);
	*content = (int) ft_atoi(s);
	n = ft_lstnew2((void *) content);
	if (!n)
	{
		free(content);
		return (0);
	}
	return (n);
}

/*
* Selects the right method depending on the format.
*/

char	**ft_parse_args(int ac, char **av)
{
	char	**args;
	int		i;

	if (ac < 2)
		return (0);
	if (ac == 2)
		return (ft_split(av[1], ' '));
	args = malloc(ac * sizeof(char *));
	if (!args)
		return (0);
	i = 0;
	while (i + 1 < ac)
	{
		args[i] = ft_strdup(av[i + 1]);
		i++;
	}
	args[i] = 0;
	return (args);
}

/*
* Parses the arguments.
*/

t_list2	*ft_parse(int ac, char **av)
{
	char	**args;
	t_list2	*l;
	int		i;

	args = ft_parse_args(ac, av);
	if (!args)
	{
		ft_printf("Error\n");
		return (0);
	}
	l = 0;
	i = -1;
	while (args[++i])
	{
		ft_lstadd_back2(&l, ft_parse_next(args[i]));
		if (!ft_lstat2(l, i) || ft_parse_is_dup(ft_lstlast2(l)))
		{
			ft_lstclear2(&l, free);
			ft_free_split(args);
			ft_printf("Error\n");
			return (0);
		}
	}
	ft_free_split(args);
	return (l);
}
