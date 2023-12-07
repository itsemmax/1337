/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:20:35 by ichaoub           #+#    #+#             */
/*   Updated: 2023/12/07 21:00:48 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ...);
int ft_putchar(int c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_putunbr(int n);
int ft_puthex(unsigned int n, char c);
int ft_putadd(void *ptr);
#endif