/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:44 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/09 14:57:45 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

size_t ft_strlen(const char *s)
{
	size_t i;


	i = 0;
	while(s && s[i])
	{
		i++;
	}
	return (i);
}
/*int main ()
{
	char *str = NULL;
	printf("%ld", ft_strlen(str));
}*/