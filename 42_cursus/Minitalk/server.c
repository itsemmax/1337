/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:45 by ichaoub           #+#    #+#             */
/*   Updated: 2024/04/02 14:21:41 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	t;

	if (signal == SIGUSR1)
		t |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", t);
		bit = 0;
		t = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid :%i\n", pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
