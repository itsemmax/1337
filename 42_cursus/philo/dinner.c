/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:51:30 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/09 19:10:07 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eat_mutex);
	if (philo->info->end_simulation == 1)
	{
		pthread_mutex_unlock(&philo->info->eat_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->eat_mutex);
	return (0);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		s_sleep(1);
	while (!dead_check(philo))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return ((void *)1);
}

void	clear_all(char *str, t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	if (str)
		printf("%s\n", str);
	while (i < info->philo_nbr)
	{
		pthread_mutex_destroy(&info->forks_mutex[i]);
		pthread_mutex_destroy(&philo[i].mtx);
		i++;
	}
	pthread_mutex_destroy(&info->writing_mutex);
	pthread_mutex_destroy(&info->eat_mutex);
	free(info->forks_mutex);
	free(info->philo);
}

void	dinner_start(t_info *info)
{
	t_philo		*philo;
	pthread_t	sup_thread;
	int			i;

	i = 0;
	philo = info->philo;
	info->start_simulation = set_time();
	if (pthread_create(&sup_thread, NULL, &sup, info))
		clear_all("Thread creation error", info, info->philo);
	while (i < info->philo_nbr)
	{
		if (pthread_create(&philo[i].thread, NULL, dinner_simulation,
				&info->philo[i]))
			clear_all("Thread creation error", info, info->philo);
		usleep(100);
		i++;
	}
	if (pthread_join(sup_thread, NULL))
		clear_all("Thread join error", info, info->philo);
	i = -1;
	while (++i < info->philo_nbr)
	{
		if (pthread_join(philo[i].thread, NULL))
			clear_all("Thread join error", info, info->philo);
	}
}
