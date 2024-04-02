/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:23 by ichaoub           #+#    #+#             */
/*   Updated: 2024/04/02 14:18:59 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char a)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((a & 0x01 << bit) != 0)
			kill(pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep (100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3 && !str_isdigit(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		if (kill (pid, 0) == -1)
		{
			ft_printf("WRONG PID, TRY AGAIN\n");
		}
		if (pid == 0)
		{
			ft_printf("WRONG PID, TRY AGAIN\n");
			exit(-1);
		}
		while (argv[2][i])
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
		ft_printf("Error : wrong formatt,try : ./client <PID> <MESSAGE\n");
}
