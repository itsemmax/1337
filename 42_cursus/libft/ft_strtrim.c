/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:04:02 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 14:04:56 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (s1[j] && ft_strchr(set, s1[j]))
	{
		j--;
	}
	return (ft_substr(s1, i, (j - i) + 1));
}

/*#include<stdio.h>
// int main()
// {
    // char *a;
    // char tab[] = "abcjgjjgjgab";
    // char set[] = "abc";
// 
    // a = ft_strtrim(tab,set);
    // printf("%s\n", a);
    // free(a);
}*/ 