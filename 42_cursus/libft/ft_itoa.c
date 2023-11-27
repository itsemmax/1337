/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:30 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/27 14:55:10 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_countdigit(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_nb_is_zero(char *p)
{
	p = (char *)malloc(2 * sizeof(char));
	if (!p)
	{
		return (NULL);
	}
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		a;
	char	*p;

	nb = n;
	a = ft_countdigit(nb);
	p = NULL;
	if (nb == 0)
		return (ft_nb_is_zero(p));
	p = (char *)malloc(sizeof(char) * (a + 1));
	if (!p)
		return (NULL);
	p[a--] = '\0';
	if (nb < 0)
	{
		p[0] = '-';
		nb *= -1;
	}
	while (nb > 0 && a >= 0)
	{
		p[a] = nb % 10 + '0';
		nb /= 10;
		a--;
	}
	return (p);
}

/*#include<stdio.h>
int main()
{
	printf("%s",ft_itoa(-123763489));
}*/