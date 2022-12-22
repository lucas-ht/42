/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:49:29 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 04:10:16 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_atoi(const char *str)
{
	size_t	n;

	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		n += (n * 9) + *str++ - '0';
	return (n);
}

/**
 * @brief Parses the argument with atoi to a rule object.
 * 
 * @param ac 
 * @param av 
 * @return t_rule* 
 */

t_rule	*ft_parse(int ac, char **av)
{
	t_rule	*rule;

	if (ac != 5 && ac != 6)
		return (ft_error(ERROR_PARSE_ARGS));
	rule = (t_rule *) malloc(sizeof(t_rule));
	if (!rule)
		return (ft_error(ERROR_MALLOC));
	rule->n = ft_atoi(av[1]);
	rule->time_die = ft_atoi(av[2]);
	rule->time_eat = ft_atoi(av[3]);
	rule->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rule->max_eat = ft_atoi(av[5]);
	if (!rule->n || !rule->time_die || !rule->time_eat || !rule->time_sleep
		|| (ac == 6 && !rule->max_eat))
		return (ft_error(ERROR_PARSE_ARGS));
	rule->running = 1;
	return (rule);
}
