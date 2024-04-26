/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:23 by ichaoub           #+#    #+#             */
/*   Updated: 2024/04/26 18:00:21 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char a)
{
	int	bit;
	int	prob;

	bit = 0;
	while (bit < 8)
	{
		if ((a & 0x01 << bit) != 0)
			prob = kill(pid, SIGUSR1);
		else
			prob = kill (pid, SIGUSR2);
		usleep (400);
		bit++;
	}
	if (prob == -1)
	{
		write(1, "WRONG PID, TRY AGAIN\n", 21);
		exit(-1);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1 || pid == 0)
		{
			write(1, "WRONG PID, TRY AGAIN\n", 21);
			exit(-1);
		}
		while (argv[2][i])
			ft_send_bits(pid, argv[2][i++]);
		ft_send_bits(pid, '\n');
	}
	else
		write(1, "Error : wrong formatt,try : ./client <PID> <MESSAGE>\n", 53);
}
