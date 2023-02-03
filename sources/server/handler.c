/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:58:33 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/27 20:54:59 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "server.h"
#include "libft.h"

int	ft_handler_end(unsigned char c, siginfo_t *info)
{
	if (c)
		ft_printf("%c", c);
	else
	{
		ft_printf("\n");
		ft_send_char(info->si_pid, 'O');
		ft_send_char(info->si_pid, 'K');
		ft_send_char(info->si_pid, '\0');
	}
	return (0);
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;

	(void) context;
	if (signum == SIGUSR1)
		c += 0b1 << i;
	if (i >= 8)
	{
		i = ft_handler_end(c, info);
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
