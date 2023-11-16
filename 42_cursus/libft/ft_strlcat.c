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
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dst == NULL)
		return (srclen);
	if (destlen >= dstsize || dstsize == 0)
		return (dstsize + srclen);
	while (src[i] && destlen + i < dstsize - 1)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}

/*#include<stdio.h>
int main()
{
	char *tab = 0;
	const char tab2[] = "hjg";
	char *tab3 = NULL;
	const char tab4[] = "chaoub";
	printf("%ld------------",ft_strlcat(tab1,tab2,8));
	printf("%ld------------%s",strlcat(tab,tab2,5),tab1);
}*/