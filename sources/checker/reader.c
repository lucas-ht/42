/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:52:21 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/06 04:25:04 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
* Reads the operation codes on the standard input.
*/

char	**ft_reader(void)
{
	char	*s;
	char	*t;

	s = 0;
	t = get_next_line(0);
	while (t)
	{
		s = ft_strjoin(s, t);
		t = get_next_line(0);
	}
	return (ft_split(s, '\n'));
}

/*
* Checks if the operation codes are valid.
*/

int	ft_isop(char **s)
{
	while (*s)
	{
		if (ft_strncmp(*s, "sa", 3)
			&& ft_strncmp(*s, "sb", 3)
			&& ft_strncmp(*s, "ss", 3)
			&& ft_strncmp(*s, "pa", 3)
			&& ft_strncmp(*s, "pb", 3)
			&& ft_strncmp(*s, "ra", 3)
			&& ft_strncmp(*s, "rb", 3)
			&& ft_strncmp(*s, "rr", 3)
			&& ft_strncmp(*s, "rra", 3)
			&& ft_strncmp(*s, "rrb", 3)
			&& ft_strncmp(*s, "rrr", 3)
		)
			return (0);
		s++;
	}
	return (1);
}
