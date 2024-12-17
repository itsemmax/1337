/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:40 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/17 00:31:10 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *str)
{
	printf(RED "%s\n" RST, str);
	exit(1);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > INT_MAX)
			print_error("the number is out of range, the INT_MAX is the limit");
	}
	return (res * sign);
}

int	check_sign(int nbr)
{
	if (nbr <= 0)
		return (0);
	else
		return (1);
}

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
				&& str[i] <= 'Z') || (str[i] >= 33 && str[i] <= 47)
				|| (str[i] >= 58 && str[i] <= 64) || (str[i] >= 123 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

void	parse_input(t_info *info, char **argv)
{
	info->philo_nbr = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	// if (info->time_to_die < 60 || info->time_to_eat < 60
	// 	|| info->time_to_sleep < 60)
	// 	print_error("Time values must be at least 60 ms");
	if (argv[5])
	{
		info->nbr_limit_meals = ft_atoi(argv[5]);
		if (ft_atoi(argv[5]) == 0)
			print_error("The max meals value must be greater than 0.");
	}
	else
		info->nbr_limit_meals = -1;
}
