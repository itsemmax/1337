/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:59:46 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/10 16:09:16 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max_meals_ate(t_info *info)
{
	int	i;
	int	done_eating;

	i = -1;
	done_eating = 0;
	if (info->nbr_limit_meals == -1)
		return (0);
	while (++i < info->philo_nbr)
	{
		pthread_mutex_lock(&info->philo[i].mtx);
		if (info->philo[i].meals_counter >= info->nbr_limit_meals)
			done_eating++;
		pthread_mutex_unlock(&info->philo[i].mtx);
	}
	if (done_eating == info->philo_nbr)
	{
		pthread_mutex_lock(&info->eat_mutex);
		info->end_simulation = 1;
		pthread_mutex_unlock(&info->eat_mutex);
		pthread_mutex_lock(&info->writing_mutex);
		printf(GREEN "All philosophers have completed their meals!\n" RST);
		pthread_mutex_unlock(&info->writing_mutex);
		return (1);
	}
	return (0);
}

int	end_simulation_check(t_info *info, int i)
{
	while (i < info->philo_nbr)
	{
		pthread_mutex_lock(&info->philo[i].mtx);
		if ((long)set_time() - info->philo[i].last_meal_time > info->time_to_die
			&& info->philo[i].is_eating == 0)
		{
			pthread_mutex_lock(&info->eat_mutex);
			info->end_simulation = 1;
			pthread_mutex_unlock(&info->eat_mutex);
			pthread_mutex_lock(&info->writing_mutex);
			printf(RED "%lu philosopher %d  died \n" RST, set_time()
				- info->start_simulation, info->philo[i].id);
			pthread_mutex_unlock(&info->writing_mutex);
			pthread_mutex_unlock(&info->philo[i].mtx);
			return (1);
		}
		pthread_mutex_unlock(&info->philo[i].mtx);
		i++;
	}
	return (0);
}

void	*sup(void *p)
{
	t_info	*info;

	info = (t_info *)p;
	while (1)
	{
		if (end_simulation_check(info, 0) != 0
			|| check_max_meals_ate(info) != 0)
			break ;
		usleep(100);
	}
	return ((void *)1);
}
