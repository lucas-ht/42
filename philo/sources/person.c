/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   person.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:45:44 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 05:39:58 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints information, a mutex is used here
 * to ensure a no message-mixing.
 * 
 * @param philo 
 * @param s 
 * @param id 
 */

void	ft_person_log(t_philo *philo, char *s, size_t id)
{
	pthread_mutex_lock(&philo->lock);
	if (philo->rule->running)
		printf("%zu %zu %s\n", ft_time(), id, s);
	pthread_mutex_unlock(&philo->lock);
}

/**
 * @brief Generates an array of person.
 * 
 * @param philo 
 * @return t_person* 
 */

t_person	*ft_person_generate(t_philo *philo)
{
	t_person	*person;
	size_t		i;

	person = (t_person *) malloc(philo->rule->n * sizeof(t_person));
	if (!person)
		return (ft_error(ERROR_MALLOC));
	i = 0;
	while (i < philo->rule->n)
	{
		person[i].uid = i;
		person[i].time_left = ft_time() + philo->rule->time_die;
		person[i].ate = 0;
		if (pthread_mutex_init(&person[i].lock, 0) != 0)
			return (ft_error(ERROR_MUTEX));
		i++;
	}
	return (person);
}

/**
 * @brief The eating routine of a person.
 * 
 * @param arg 
 */

static void	ft_person_eat(t_arg *arg)
{
	pthread_mutex_lock(&arg->forks[0]->lock);
	ft_person_log(arg->philo, TEXT_FORK, arg->uid);
	if (!arg->forks[1])
	{
		ft_sleep(arg->philo, arg->philo->rule->time_die * 2);
		return ;
	}
	pthread_mutex_lock(&arg->forks[1]->lock);
	ft_person_log(arg->philo, TEXT_FORK, arg->uid);
	pthread_mutex_lock(&arg->self->lock);
	ft_person_log(arg->philo, TEXT_EAT, arg->uid);
	arg->self->time_left = ft_time() + arg->philo->rule->time_die;
	pthread_mutex_unlock(&arg->self->lock);
	ft_sleep(arg->philo, arg->philo->rule->time_eat);
	pthread_mutex_lock(&arg->self->lock);
	arg->self->ate++;
	pthread_mutex_unlock(&arg->self->lock);
	pthread_mutex_unlock(&arg->forks[0]->lock);
	pthread_mutex_unlock(&arg->forks[1]->lock);
}

/**
 * @brief The loop of every thread.
 * 
 * @param param 
 * @return void* 
 */

void	*ft_person_loop(void *param)
{
	t_arg	*arg;

	arg = (t_arg *) param;
	if (arg->uid % 2)
		ft_sleep(arg->philo, arg->philo->rule->time_eat);
	while (arg->philo->rule->running)
	{
		ft_person_eat(arg);
		if (!arg->philo->rule->running)
			return (0);
		ft_person_log(arg->philo, TEXT_SLEEP, arg->uid);
		ft_sleep(arg->philo, arg->philo->rule->time_sleep);
		if (!arg->philo->rule->running)
			return (0);
		ft_person_log(arg->philo, TEXT_THINK, arg->uid);
	}
	return (0);
}
