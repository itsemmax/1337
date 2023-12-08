/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:33:08 by ichaoub           #+#    #+#             */
/*   Updated: 2023/12/08 16:55:30 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	while (str[i])
	{
		ft_putchar(str[i++]);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = n;
	if (n < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		count += ft_putchar(nb + '0');
	}
	else
	{
		count += ft_putnbr(nb / 10);
		count += ft_putchar(nb % 10 + '0');
	}
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		count += ft_putchar(n + '0');
	}
	else
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}

int	ft_puthex(unsigned long n, char c)
{
	int		count;
	char	*p;

	count = 0;
	if (c == 'x')
		p = "0123456789abcdef";
	else if (c == 'X')
		p = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(p[n]);
	else
	{
		count += ft_puthex(n / 16, c);
		count += ft_putchar(p[n % 16]);
	}
	return (count);
}

int	ft_putadd(void *ptr)
{
	int				count;
	unsigned long	p;

	count = 0;
	p = 0;
	if (!ptr)
		return (ft_putstr("0x0"));
	p = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_puthex(p, 'x');
	return (count);
}
