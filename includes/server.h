/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:57:46 by lhutt             #+#    #+#             */
/*   Updated: 2022/11/26 06:07:00 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

int		ft_handler_end(unsigned char c, siginfo_t *info);
void	ft_handler(int signum, siginfo_t *info, void *context);
void	ft_send_char(int pid, char c);

#endif
