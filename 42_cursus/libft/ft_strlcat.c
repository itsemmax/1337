/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:49:19 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 13:50:28 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (destlen >= dstsize || !dst)
		return (dstsize + srclen);
	while (src[i] && destlen + i < dstsize - 1)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char *tab = 0;
// 	char *tab2 = NULL;
// 	char tab3[] = "jhgx";
// 	const char tab4[] = "chaoub";
// 	printf("%ld------------\n",ft_strlcat(tab2,tab3,0));
// 	//printf("%lu------------",strlcat(tab3,tab2,0));
// }