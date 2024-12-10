/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:59:51 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/10 16:35:00 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	set_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	s_sleep(size_t time)
{
	size_t	start;

	start = set_time();
	while ((set_time() - start) < time)
		usleep(100);
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
