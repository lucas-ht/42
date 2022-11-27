/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:58:33 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/27 22:20:23 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"
#include "libft.h"

int	g_received;

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (0 * ft_printf("Usage: ./client [PID: int] \"[message: str]\"\n"));
	pid = ft_atoi(av[1]);
	if (!pid)
		return (0 * ft_printf("Invalid PID!\n"));
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	g_received = 0;
	i = 0;
	while (av[2][i - 1] || !i)
		ft_send_char(pid, av[2][i++]);
	while (!g_received)
		pause();
	return (0);
}
