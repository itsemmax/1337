/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:55 by ichaoub           #+#    #+#             */
/*   Updated: 2024/08/23 17:07:36 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef	struct s_philo
{
	int				id;
	long			meals_counter; //nbr of meals the philo has eaten 
	int				full; // 1 for full , 0 for not
	long			last_meal_time; //timestamp of the philo's last meal,used for checking if they are still alive.
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thread; //thread handle for the philo's thread
	t_info			*info;
}				t_philo;

typedef struct s_info
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation; // starting time
	int		end_simulation; //a philo dies or all philos full
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	writing_mutex;
	t_philo	*philo;

}				t_info;

int		ft_atoi(char *str);
int		check_sign(int nbr);
int		check_digits(char *str);
void	print_error(char *str);
void	parse_input(t_info *info,char **argv);
int		data_init(t_info *info);
void	dinner_start(t_info *info);
void	clear(t_info *info);
int		philos_init(t_info *info);
int		mutex_init(t_info *info);

#endif