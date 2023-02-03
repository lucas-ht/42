/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:41:20 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 04:09:08 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Generates an array of forks.
 * 
 * @param philo 
 * @return t_fork* 
 */

t_fork	*ft_fork_generate(t_philo *philo)
{
	t_fork	*fork;
	size_t	i;

	fork = (t_fork *) malloc(philo->rule->n * sizeof(t_fork));
	if (!fork)
		return (ft_error(ERROR_MALLOC));
	i = 0;
	while (i < philo->rule->n)
	{
		fork[i].uid = i;
		if (pthread_mutex_init(&fork[i].lock, 0) != 0)
			return (ft_error(ERROR_MUTEX));
		i++;
	}
	return (fork);
}

/**
 * @brief Determines the two forks next to a philosopher.
 * 
 * @param philo 
 * @param i 
 * @return t_fork** 
 */

t_fork	**ft_fork_get(t_philo *philo, size_t i)
{
	t_fork	**fork;

	fork = (t_fork **) malloc(2 * sizeof(t_fork *));
	if (!fork)
		return (ft_error(ERROR_MALLOC));
	fork[0] = &philo->fork[i];
	fork[1] = 0;
	if (i > 0)
		fork[1] = &philo->fork[i - 1];
	else if (philo->rule->n > 1)
		fork[1] = &philo->fork[philo->rule->n - 1];
	return (fork);
}
