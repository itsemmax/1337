/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:52:05 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 16:19:41 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// #include<stdio.h>
// #include<fcntl.h>

// int main()
// {
// 	int fd;

// 	fd = open("test.txt",O_CREAT | O_WRONLY);
// 	ft_putstr_fd("hello imane" , fd);
// 	printf("%d", fd);
// 	close(fd);
// }