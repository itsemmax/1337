/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:57 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/27 14:47:21 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
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