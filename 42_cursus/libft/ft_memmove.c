/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:07 by ichaoub           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/14 16:21:08 by marvin           ###   ########.fr       */
=======
/*   Updated: 2023/11/29 14:06:40 by ichaoub          ###   ########.fr       */
>>>>>>> 96e6eced562d767906248a36bee512a36d62b451
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

<<<<<<< HEAD
	a = (unsigned char *) dest;
	b = (unsigned char *) src;
	if(!a && !b)
	{
		return (NULL);
	}
=======
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (a == b)
		return (a);
	if (!a && !b)
		return (NULL);
>>>>>>> 96e6eced562d767906248a36bee512a36d62b451
	if (a > b)
	{
		while (n >= 0)
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
<<<<<<< HEAD
#include <stdio.h>
int main(){
	char p[]= "imane";
	char a[] = "hello";
	ft_memmove(p, b, 5);
	printf("%s", p);
}
=======
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
>>>>>>> 96e6eced562d767906248a36bee512a36d62b451