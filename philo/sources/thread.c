/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 02:03:36 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 05:38:37 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Sleeps while being able to abort.
 * 
 * @param philo 
 * @param delay 
 */

void	ft_sleep(t_philo *philo, size_t delay)
{
	delay += ft_time();
	while (philo->rule->running && delay > ft_time())
		usleep(100);
}

/**
 * @brief Returns the current time in ms.
 * 
 * @return size_t 
 */

size_t	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief Create an arugment object.
 * 
 * @param philo 
 * @return t_arg* 
 */

static t_arg	*ft_thread_arg(t_philo *philo)
{
	t_arg	*arg;
	size_t	i;

	arg = (t_arg *) malloc(philo->rule->n * sizeof(t_arg));
	if (!arg)
		return (ft_error(ERROR_MALLOC));
	i = 0;
	while (i < philo->rule->n)
	{
		arg[i].philo = philo;
		arg[i].uid = i;
		arg[i].self = &philo->person[i];
		arg[i].forks = ft_fork_get(philo, i);
		i++;
	}
	return (arg);
}

/**
 * @brief Monitors the status of the philosophers,
 * also checks if one died or if all of them have eaten enough.
 * 
 * @param philo 
 */

static void	ft_thread_handler(t_philo *philo)
{
	size_t	i;
	int		ate;

	while (philo->rule->running)
	{
		i = 0;
		ate = philo->rule->max_eat != 0;
		while (philo->rule->running && i < philo->rule->n)
		{
			pthread_mutex_lock(&philo->person[i].lock);
			if (philo->person[i].time_left < ft_time())
			{
				ft_person_log(philo, TEXT_DIE, i);
				philo->rule->running = 0;
			}
			if (ate && philo->person[i].ate < philo->rule->max_eat)
				ate = 0;
			pthread_mutex_unlock(&philo->person[i].lock);
			i++;
		}
		if (ate)
			philo->rule->running = 0;
	}
}

/**
 * @brief Initialize everything and launches the threads.
 * When they finish, it also closes them to exit cleanly.
 * 
 * @param philo 
 * @return int 
 */

int	ft_thead(t_philo *philo)
{
	t_arg	*arg;
	size_t	i;

	philo->person = ft_person_generate(philo);
	philo->fork = ft_fork_generate(philo);
	arg = ft_thread_arg(philo);
	if (!philo->rule || !philo->fork || !arg)
		return (0);
	i = 0;
	while (i < philo->rule->n)
	{
		if (pthread_create(&philo->person[i].thread,
				0, &ft_person_loop, (void *) &arg[i]) != 0)
			return (ft_error_int(ERROR_THREAD));
		i++;
	}
	ft_thread_handler(philo);
	i = 0;
	while (i < philo->rule->n)
	{
		pthread_join(philo->person[i].thread, 0);
		i++;
	}
	return (1);
}
