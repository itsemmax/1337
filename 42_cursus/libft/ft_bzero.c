/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:56:12 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 12:06:52 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

/*#include<stdio.h>
#include<string.h>
int main()
{
	int tab[] = {1,3,4,5,6,};
	ft_bzero(tab,8);
	for (int i=0;i<5;i++)
	{
		printf("%i------",tab[i]);
	}
}*/