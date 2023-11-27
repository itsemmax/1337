/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:01 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/20 17:51:01 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

void	ft_strncpy(char *dst, char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] && i < c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_free(char **p, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

char	**ft_allocate(int c2)
{
	char	**p;

	p = (char **)malloc(sizeof (char *) * (c2 + 1));
	if (!p)
	{
		return (NULL);
	}
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**p;

	i = -1;
	count = count_word((char *)s, c);
	p = ft_allocate(count);
	while (++i < count)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s)
		{
			s++;
			j++;
		}
		p[i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!p[i])
			ft_free(p, i);
		ft_strncpy(p[i], (char *)(s - j), j);
	}
	p[i] = NULL;
	return (p);
}
// #include <stdio.h>
// int main()
// {
// 	int i = 0;

// 	char *p = " hello       world      imane ";
// 	char c = ' ';
// 	char **a = ft_split(p,c);
// 	while(i < 3)
// 	{
// 		printf("%s",a[i]);
// 		printf("\n");
// 		i++;
// 	}
// 	free(a);
// }