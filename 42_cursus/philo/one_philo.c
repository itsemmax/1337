/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:59:30 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/17 01:21:59 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_info *info, int r_fork)
{
	s_sleep(info->philo->last_meal_time, info->philo);
	pthread_mutex_unlock(&info->forks_mutex[r_fork]);
	return (1);
}
