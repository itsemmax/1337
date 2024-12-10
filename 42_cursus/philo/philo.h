/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:55 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/10 16:31:57 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# define RST "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

typedef struct s_philo
{
	int				id;
	long			meals_counter;
	int				is_eating;
	long			last_meal_time;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	mtx;
	pthread_t		thread;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	long			philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			start_simulation;
	int				end_simulation;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	writing_mutex;
	t_philo			*philo;

}					t_info;

long				ft_atoi(char *str);
int					check_sign(int nbr);
int					check_digits(char *str);
void				print_error(char *str);
void				parse_input(t_info *info, char **argv);
int					data_init(t_info *info, t_philo *philo);
void				dinner_start(t_info *info);
int					philos_init(t_info *info);
int					mutex_init(t_info *info);
size_t				set_time(void);
void				s_sleep(size_t time);
void				lock_forks(t_philo *philo, int r_fork, int l_fork);
void				is_eating(t_philo *philo);
void				start_eating(t_philo *philo);
void				unlock_forks(t_philo *philo, int r_fork, int l_fork);
void				is_sleeping(t_philo *philo);
void				is_thinking(t_philo *philo);
int					check_max_meals_ate(t_info *info);
int					end_simulation_check(t_info *info, int i);
void				*sup(void *p);
int					one_philo(t_info *info);
int					dead_check(t_philo *philo);
void				*dinner_simulation(void *data);
void				clear_all(char *str, t_info *info, t_philo *philo);
void				dinner_start(t_info *info);
#endif