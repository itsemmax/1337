/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:57 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 15:57:22 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

//#include<stdio.h>
//#include<fcntl.h>
//int main()
//{
//	int fd;
//	fd = open("samira.txt", O_CREAT | O_WRONLY);
//	ft_putendl_fd("hello world", fd);
//	printf("%d", fd);
//	close(fd);
//}