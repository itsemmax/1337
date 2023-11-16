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
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *) s)[i] == (unsigned char ) c)
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