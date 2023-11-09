/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:59 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/09 14:57:00 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *a;
	unsigned char *b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if(!a && !b)
	{
		return(0);
	}
	while(a[i] && b[i] && a[i] == b[i] && i < n)
	{
		i++;
	}
	if(i == n)
	{
		return (0);
	}
	return (a[i] - b[i]);
}

/*#include<stdio.h>
#include<string.h>
int main()
{
	char tab[] = "hello";
	char tab1[] = "helrld";
	printf("%d | %d",ft_memcmp(tab,tab1,3),memcmp(tab,tab1,3));
}*/