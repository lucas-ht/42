/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:57:49 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/26 08:06:33 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

extern int		g_received;

int		ft_handler_end(unsigned char c);
void	ft_handler(int signum);
void	ft_send_char(int pid, char c);

#endif
