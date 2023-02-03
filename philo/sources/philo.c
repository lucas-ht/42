/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:45:38 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 04:27:58 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @param number_of_philos	: uint - The total number of philos (and forks).
 * @param time_to_die		: uint - The time before death after a meal (ms).
 * @param time_to_eat		: uint - The time a philo take to eat (ms).
 * @param time_to_sleep		: uint - The tima a philo sleep (ms).
 * @param number_of_times_each_philo_must_eat
 * 							: uint - Optional, can finish the simulation.
 */

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo));
	if (!philo)
		return (ft_error_int(ERROR_MALLOC));
	philo->rule = ft_parse(ac, av);
	if (!philo->rule)
		return (1);
	return (!ft_thead(philo));
}
