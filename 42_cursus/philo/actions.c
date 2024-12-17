/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:24:50 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/17 01:39:49 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philo *philo, int r_fork, int l_fork)
{
	pthread_mutex_lock(&philo->info->forks_mutex[r_fork]);
	if (dead_check(philo))
	{
		pthread_mutex_unlock(&philo->info->forks_mutex[r_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(GREEN "%lu philo %d 🍴 has taken a fork\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	if (philo->info->philo_nbr == 1)
		return ((void )one_philo(philo->info, r_fork));
	pthread_mutex_lock(&philo->info->forks_mutex[l_fork]);
	if (dead_check(philo))
	{
		pthread_mutex_unlock(&philo->info->forks_mutex[r_fork]);
		pthread_mutex_unlock(&philo->info->forks_mutex[l_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(GREEN "%lu philo %d 🍴 has taken a second fork\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
}

void	unlock_forks(t_philo *philo, int r_fork, int l_fork)
{
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_unlock(&philo->info->forks_mutex[r_fork]);
	pthread_mutex_unlock(&philo->info->forks_mutex[l_fork]);
}

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 1;
	philo->meals_counter++;
	philo->last_meal_time = set_time();
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(YELLOW "%lu philo %d 😋 is eating\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	s_sleep(philo->info->time_to_eat, philo);
}

void	is_eating(t_philo *philo)
{
	int	r_fork;
	int	l_fork;

	r_fork = philo->r_fork;
	l_fork = philo->l_fork;
	if (philo->l_fork < philo->r_fork)
	{
		r_fork = philo->l_fork;
		l_fork = philo->r_fork;
	}
	if (dead_check(philo))
		return ;
	lock_forks(philo, r_fork, l_fork);
	if (dead_check(philo))
		return ;
	start_eating(philo);
	unlock_forks(philo, r_fork, l_fork);
}

void	is_sleeping(t_philo *philo)
{
	if (dead_check(philo))
		return ;
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf("%lu philo %d 😴 is sleeping\n", set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	s_sleep(philo->info->time_to_sleep, philo);
	if (philo->info->philo_nbr % 2 == 1)
		usleep(300);
}
