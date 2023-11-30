/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:59:27 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 12:09:00 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	if (size != 0 && nmemb > __SIZE_MAX__ / size)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero (p, nmemb * size);
	return (p);
}

// #include<stdio.h>
// int main()
// {
// 	int *p;
// 	p = (int *) ft_calloc(20 , sizeof(int));
// 	for(int i = 0; i < 20 ;i++)
// 	{
// 		printf("%d",p[i]);		
// 	}
// 	free(p);
// 	printf("\n");
// }

// #include<stdio.h>
// int main()
// {
// 	char *p;
// 	p = (char *) ft_calloc(20 , sizeof(char));
// 	for(int i = 0; i < 20 ;i++)
// 	{
// 		printf("%c",p[i] + 48);		
// 	}
// 	free(p);
// 	printf("\n");
// }