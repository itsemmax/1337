/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:51:30 by ichaoub           #+#    #+#             */
/*   Updated: 2024/08/23 18:00:43 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dinner_start(t_info *info)
{
	int i;

	i = -1;
	if(info->nbr_limit_meals == 0)
			return ;
	else if(info->philo_nbr == 1)
		one_philo(&info);//todo
	else
	{
		while(++i <= info->philo_nbr)
			safe_thread_handle(&info->philo[i].id,dinner_simulation(&info),&info->philo[i]);
	}
}
