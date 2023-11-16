/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:16:30 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/13 13:46:42 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		return ((char *) s);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char) c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}
