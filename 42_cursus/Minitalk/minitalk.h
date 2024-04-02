/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:49:02 by ichaoub           #+#    #+#             */
/*   Updated: 2024/04/02 14:20:26 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *nptr);
int		str_isdigit(char *str);
void	ft_send_bits(int pid, char a);
void	ft_handler(int signal);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
#endif