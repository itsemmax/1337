/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:21 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/09 14:57:26 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while(s && s[i])
	{
		if(s[i] == c)
		{
			return((char *)s + i);
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
	printf("%s\n", strchr(tab,'l'));
}*/