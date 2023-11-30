/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:51:54 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 15:57:12 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
// #include<stdio.h>
// #include<fcntl.h>
// int main()
// {
// int fd;

// fd = open("emma.txt",O_CREAT | O_WRONLY);
// ft_putchar_fd('a', fd);
// printf("%d\n",fd);
// close(fd);
// }