/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:49 by ichaoub           #+#    #+#             */
/*   Updated: 2024/08/23 04:11:44 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	while(i <= info->philo_nbr)
	{
		info->philo[i].id = i + 1;
		info->philo[i].meals_counter = 0;
		info->philo[i].full = 0;
		info->philo[i].r_fork = &info->forks_mutex[i];
		if (i == 0)
			info->philo[i].l_fork = &info->forks_mutex[info->philo_nbr - 1];
		else
			info->philo[i].r_fork = &info->forks_mutex[i - 1];
		i++;
				
	}
	
}
