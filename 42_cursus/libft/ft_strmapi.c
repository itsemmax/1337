/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:25 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 16:40:04 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include<stdio.h>

char test_fct(unsigned int a, char b)
{
	printf("index %u---------char %c\n",a,b);
	return(0);
}

int main()
{
	char *result;
	result = ft_strmapi("hello",&test_fct);
	printf("%s",result);
}*/
// #include<stdio.h>

// char	ft_test(unsigned int i, char c)
// {
// 	(void)i;
// 	if(c > 'a' && c <= 'z')
// 		return(c -  32);
// 	else
// 		return(c);
// }

// int main()
// {
// 	char tab[] = "helloHGHGDF";
// 	printf("%s",ft_strmapi(tab,ft_test));
// }