/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:54:48 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 15:34:21 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return(ft_strdup(""));
	}
	if (ft_strlen(s) < start + len)
		p = malloc((ft_strlen(s) - start) + 1);
	else
		p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len && s[start])
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
/*#include<stdio.h>

int main()
{
	char *p;
	p =ft_substr("hello world",0,10);
	printf("%s",p);
	free(p);
}*/