/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:53 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 15:27:32 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		if (a[i] == (unsigned char ) c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (NULL);
}
/*#include<stdio.h>
#include<string.h>
int main()
{
	char tab[] = "hello world";
	printf("%s",(char *) memchr(tab,'l',4));
}*/