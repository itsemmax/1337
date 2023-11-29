/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:07 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/29 14:06:40 by ichaoub          ###   ########.fr       */
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
// #include <stdio.h>
// #include <string.h>
// int	main(void){
// 	char p[]= "hello imane";
// 	char p1[]= "hello imane"; 
// 	ft_memmove(p + 3, p, 11);
// 	memmove(p1 + 3, p1, 11);
// 	printf("%s\n", p + 3);
// 	printf("%s\n", p1 + 3);
// }