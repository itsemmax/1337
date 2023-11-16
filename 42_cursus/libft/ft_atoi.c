/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:02 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 16:08:15 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	t;

	i = 0;
	sign = 1;
	t = 0;
	while (nptr[i] == ' ' || ((nptr[i] >= 9) && (nptr[i] <= 13)))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		t = t * 10 + (nptr[i] - 48);
		i++;
	}
	return (t * sign);
}
/*#include<stdio.h>

int main()
{
	printf("%i\n",ft_atoi("    +6354135hrtu"));
}*/