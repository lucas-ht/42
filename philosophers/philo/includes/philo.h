/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhutt <lhutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:43:24 by lhutt             #+#    #+#             */
/*   Updated: 2022/12/22 05:03:59 by lhutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "error.h"

# define TEXT_FORK			"has taken a fork"
# define TEXT_EAT			"is eating"
# define TEXT_SLEEP			"is sleeping"
# define TEXT_THINK			"is thinking"
# define TEXT_DIE			"died"

/**
 * @brief Struct cointaining every rules of the simulation.
 *        n 				: uint - The number of philosophers.
 *        max_eat 			: uint - The number of time they need to eat.
 */

typedef struct s_rule
{
	size_t	n;
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
	size_t	max_eat;
	int		running;
}	t_rule;

/**
 * @brief Struct containing the necessary information for a person.
 * 
 */

typedef struct s_person
{
	size_t			uid;
	pthread_t		thread;
	size_t			ate;
	size_t			time_left;
	pthread_mutex_t	lock;
}	t_person;

typedef struct s_fork
{
	size_t			uid;
	pthread_mutex_t	lock;
}	t_fork;

/**
 * @brief t_philo is a wrapper struct containing everything.
 * 
 */

typedef struct s_philo
{
	t_rule			*rule;
	t_person		*person;
	t_fork			*fork;
	pthread_mutex_t	lock;
}	t_philo;

/**
 * @brief t_arg is a wrapper struct containing everything for a given person,
 * used in threads.
 * 
 */

typedef struct s_arg
{
	t_philo		*philo;
	size_t		uid;
	t_person	*self;
	t_fork		**forks;
}	t_arg;

// parser.c
t_rule		*ft_parse(int ac, char **av);

// person.c
void		ft_person_log(t_philo *philo, char *s, size_t id);
t_person	*ft_person_generate(t_philo *philo);
void		*ft_person_loop(void *param);

// fork.c
t_fork		*ft_fork_generate(t_philo *philo);
t_fork		**ft_fork_get(t_philo *philo, size_t i);

// thread.c
void		ft_sleep(t_philo *philo, size_t delay);
size_t		ft_time(void);
int			ft_thead(t_philo *philo);

#endif
