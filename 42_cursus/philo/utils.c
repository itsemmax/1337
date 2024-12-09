/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:59:51 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/09 19:15:45 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	set_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	s_sleep(size_t time)
{
	size_t	start;

	start = set_time();
	while ((set_time() - start) < time)
		usleep(500);
}

void	is_eating(t_philo *philo)
{
	if (dead_check(philo))
		return ;
	pthread_mutex_lock(&philo->info->forks_mutex[philo->r_fork]);
	if (dead_check(philo))
	{
		pthread_mutex_unlock(&philo->info->forks_mutex[philo->r_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(GREEN "%lu philo %d 🍴 has taken a fork\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	pthread_mutex_lock(&philo->info->forks_mutex[philo->l_fork]);
	if (dead_check(philo))
	{
		pthread_mutex_unlock(&philo->info->forks_mutex[philo->r_fork]);
		pthread_mutex_unlock(&philo->info->forks_mutex[philo->l_fork]);
		return ;
	}
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(GREEN "%lu philo %d 🍴 has taken a second fork\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 1;
	philo->meals_counter++;
	philo->last_meal_time = set_time();
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(YELLOW "%lu philo %d 😋 is eating\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	s_sleep(philo->info->time_to_eat);
	pthread_mutex_lock(&philo->mtx);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mtx);
	pthread_mutex_unlock(&philo->info->forks_mutex[philo->r_fork]);
	pthread_mutex_unlock(&philo->info->forks_mutex[philo->l_fork]);
}

void	is_sleeping(t_philo *philo)
{
	if (dead_check(philo))
		return ;
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf("%lu philo %d 😴 is sleeping\n", set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
	s_sleep(philo->info->time_to_sleep);
}

void	is_thinking(t_philo *philo)
{
	if (dead_check(philo))
		return ;
	pthread_mutex_lock(&philo->info->writing_mutex);
	printf(BLUE "%lu philo %d 🤔 is thinking\n" RST, set_time()
		- philo->info->start_simulation, philo->id);
	pthread_mutex_unlock(&philo->info->writing_mutex);
}
