/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:58:33 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/26 07:34:40 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "client.h"
#include "libft.h"

int		g_received;

int	ft_handler_end(unsigned char c)
{
	if (c)
		ft_printf("%c", c);
	else
	{
		ft_printf("\n");
		g_received = 1;
	}
	return (0);
}

void	ft_handler(int signum)
{
	static int				i;
	static unsigned char	c;

	if (signum == SIGUSR1)
		c += 0b1 << i;
	if (i >= 8)
	{
		i = ft_handler_end(c);
		c = 0;
		return ;
	}
	i++;
}

void	ft_send_char(int pid, char c)
{
	int	b;

	b = 0;
	while (b <= 8)
	{
		if (c & 0b1 << b)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(WAIT_TIME);
		b++;
	}
}
