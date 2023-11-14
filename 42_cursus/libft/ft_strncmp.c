/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:50 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 13:53:58 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((!s1 && !s2) || !n)
	{
		return (0);
	}
	while (s1[i] == s2[i] && i < n)
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char) s2[i]);
}
/*#include<stdio.h>
#include<string.h>
int main()
{
	char tab[] = "hello";
	char tab2[] = "hello";
	printf("%i\n",ft_strncmp(tab,tab2,2));
	printf("%i\n",strncmp(tab,tab2,2));
}*/