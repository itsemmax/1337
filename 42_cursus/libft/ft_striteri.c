/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:19 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 16:44:16 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
	{
		return ;
	}
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include<stdio.h>

void	test(unsigned int a, char *b)
{
	printf("s[%i] = %c\n",a,*b);
}

int	main(void)
{
	ft_striteri("hello",&test);
}*/

// #include<stdio.h>

// void	ft_test(unsigned int i, char *s)
// {
// 	(void)i;
// 	if(*s >= 'a' && *s <= 'z')
// 	{
// 		*s -= 32;
// 	}
// }

// int main()
// {
// 	char s[] = "hello";
// 	ft_striteri(s,ft_test);
// 	printf("%s",s);
// }