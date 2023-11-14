/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:14 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 13:45:32 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i ;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) s;
	while (n > 0)
	{
		p[i] = c;
		n--;
		i++;
	}
	return (s);
}
/*#include<stdio.h>
#include<string.h>
int main()
{
	char tab[] = "hello";
	printf("%s",(char *) ft_memset(tab,'a',2));
	for (int i=0;i<5;i++)
	{
		printf("%c------",tab[i]);
	}
}*/