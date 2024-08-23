/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:49 by ichaoub           #+#    #+#             */
/*   Updated: 2024/08/23 17:07:30 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_info *info)
{
	int i;

	i = 0;
	while(i <= info->philo_nbr)
	{
		if(pthread_mutex_init(&info->forks_mutex[i],NULL));
			return(0);
		i++;
	}
	if(pthread_mutex_init(&info->eat_mutex,NULL))
		return(0);
	if(pthread_mutex_init(&info->writing_mutex,NULL))
		return(0);
}

int	philos_init(t_info *info)
{
	int i;

	i = 0;
	while(i <= info->philo_nbr)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meals_counter = 0;
		info->philo[i].full = 0;
		info->philo[i].l_fork = &info->forks_mutex[(i + 1) % info->philo_nbr];
		info->philo[i].r_fork = &info->forks_mutex[i];
		if (info->philo[i].id % 2)
		{
			info->philo[i].l_fork = &info->forks_mutex[i];
			info->philo[i].r_fork = &info->forks_mutex[(i + 1) % info->philo_nbr];
		}
		i++;		
	}
	return(1);
}

int	data_init(t_info *info)
{
	int i;

	i = 0;
	info->start_simulation = 0;
	info->philo = malloc(sizeof(t_philo) * info->philo_nbr);
	if(!info->philo)
	{
		printf("malloc error");
		return(0);
	}
	if(!philos_init(&info))
		return(0);
	info->forks_mutex = malloc(sizeof(pthread_mutex_t) * info->philo_nbr);
	if(!info->forks_mutex)
	{
		printf("malloc error");
		return(0);
	}
	if(!mutex_init(&info))
		return(0);
}
