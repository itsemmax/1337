/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:00 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/09 14:58:01 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while(s && i >= 0)
	{
		if(s[i] == c)
		{
			return((char*)s + i);
		}
		i--;
	}
	return(NULL);
}

/*#include<stdio.h>
int main(){
	char tab[] = "hellohsdfukhflbsjvbj";
	char a = 'l';
	printf("%s", ft_strrchr(tab,a));
}*/