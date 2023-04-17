/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:57:45 by lhutt             #+#    #+#             */
/*   Updated: 2023/03/27 03:00:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# ifndef DEFAULT_FILE_DESCRIPTOR
#  define DEFAULT_FILE_DESCRIPTOR 1
# endif

int		ft_printf(const char *s, ...);

int		ft_print_arg_char(char c);
int		ft_print_arg_string(char *s);
int		ft_print_arg_pointer(void *p);
int		ft_print_arg_int(int n);
int		ft_print_arg_unsigned_int(unsigned int n);
int		ft_print_arg_hex_lowercase(int n);
int		ft_print_arg_hex_uppercase(int n);

#endif
