/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:54 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/27 15:01:15 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include<stdio.h>
// #include<fcntl.h>
// int main()
// {
// 	int fd;

// 	fd = open("emma.txt",O_CREAT | O_WRONLY);
// 	ft_putchar_fd('a', fd);
// 	printf("%d\n",fd);
// 	close(fd);
// }