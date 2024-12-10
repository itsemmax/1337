/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:49 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/10 16:59:55 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_nbr)
	{
		if (pthread_mutex_init(&info->forks_mutex[i], NULL))
			return (0);
		if (pthread_mutex_init(&info->philo[i].mtx, NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&info->eat_mutex, NULL))
		return (0);
	if (pthread_mutex_init(&info->writing_mutex, NULL))
		return (0);
	return (1);
}

int	philos_init(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_nbr)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meals_counter = 0;
		info->philo[i].info = info;
		info->philo[i].is_eating = 0;
		info->philo[i].r_fork = i;
		info->philo[i].l_fork = (i + 1) % info->philo_nbr;
		info->philo[i].last_meal_time = set_time();
		i++;
	}
	return (1);
}

int	data_init(t_info *info, t_philo *philo)
{
	info->philo = philo;
	info->end_simulation = 0;
	info->philo = malloc(sizeof(t_philo) * info->philo_nbr);
	if (!info->philo)
		print_error("malloc error");
	if (info->philo_nbr == 1)
	{
		one_philo(info);
		free(info->philo);
		return (0);
	}
	if (!philos_init(info))
		return (0);
	info->forks_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_nbr);
	if (!info->forks_mutex)
		print_error("malloc error");
	if (!mutex_init(info))
	{
		free(info->philo);
		free(info->forks_mutex);
		return (0);
	}
	return (1);
}
