/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:59:30 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/10 16:00:11 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_info *info)
{
	info->philo->id = 1;
	pthread_mutex_init(&info->writing_mutex, NULL);
	info->start_simulation = set_time();
	pthread_mutex_lock(&info->writing_mutex);
	printf(GREEN "%lu philo %d has taken a fork\n" RST, set_time()
		- info->start_simulation, info->philo->id);
	pthread_mutex_unlock(&info->writing_mutex);
	s_sleep(info->time_to_die);
	pthread_mutex_lock(&info->writing_mutex);
	printf(RED "%lu philo %d died (couldn't eat with one fork) \n" RST,
		set_time() - info->start_simulation, info->philo->id);
	pthread_mutex_unlock(&info->writing_mutex);
	pthread_mutex_destroy(&info->writing_mutex);
	return (1);
}
