/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:13:13 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/05 02:15:41 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

int		ft_parse_is_dup(t_list2 *stack);
t_list2	*ft_parse_next(char *s);
char	**ft_parse_args(int ac, char **av);
t_list2	*ft_parse(int ac, char **av);

#endif
