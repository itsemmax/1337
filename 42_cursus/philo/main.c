/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 03:29:32 by ichaoub           #+#    #+#             */
/*   Updated: 2024/12/09 21:20:27 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	t_philo	*philo;

	philo = NULL;
	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
			if ((ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) > 200)
				|| !check_sign(ft_atoi(argv[i])) || !check_digits(argv[i]))
				print_error("urs args is not valid");
			i++;
		}
		parse_input(&info, argv);
		if (!data_init(&info, philo))
			return (0);
		dinner_start(&info);
	}
	else
		print_error("wrong input, please enter 4 or 5 args");
	return (0);
}
