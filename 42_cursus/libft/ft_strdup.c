/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:22 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 13:47:11 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((ft_strlen(s) +1) * sizeof(char));
	if (!dst)
	{
		return ((NULL));
	}
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*#include<stdio.h>

int main()
{
	char a[] = "hello world";
	char *b;

	b = ft_strdup(a);
	printf("%s\n",a);
	printf("%s\n",b);
	free(b);
}*/