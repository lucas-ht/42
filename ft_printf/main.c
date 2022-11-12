/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:31:36 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/12 03:47:06 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *p = "Hello";
	int	a;
	int b;

	a = ft_printf("%p", (void *)-14523);
	printf("\n");
	b = printf("%p", (void *)-14523);


	printf("\nresult:\nft: %d\nin: %d\n", a, b);

	return (0);
}
