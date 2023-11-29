/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:07 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/29 10:27:00 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (a == b)
		return (a);
	if (!a && !b)
		return (NULL);
	if (a > b)
	{
		while (n > 0)
		{
			a[n - 1] = b[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(a, b, n);
	}
	return (dest);
}
/*#include <stdio.h>
int	main(void){
	char p[]= "hello";
	char a[] = "imane";
	ft_memmove(p, a, 5);
	printf("%s", p);
}*/