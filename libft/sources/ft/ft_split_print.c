/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:34:07 by lucas             #+#    #+#             */
/*   Updated: 2023/01/25 23:36:08 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_print(char *name, char **strs)
{
	int	i;

	i = -1;
	printf("%s\n", name);
	while (strs[++i])
		printf("%s[%d] = %s\n", name, i, strs[i]);
}
