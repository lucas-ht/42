/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:52:15 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/21 20:30:06 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "stdio.h"

# define ERROR_MALLOC		"An error occured while allocating memory."

# define ERROR_PARSE	 	"An error occured while parsing the arguments."
# define ERROR_PARSE_ARGS	"The given arguments are invalid."

# define ERROR_THREAD		"An error occured while creating a thread."
# define ERROR_MUTEX		"An error occured while creating a mutex."

void	*ft_error(char *s);
int		ft_error_int(char *s);

#endif
