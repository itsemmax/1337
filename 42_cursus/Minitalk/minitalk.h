#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include"ft_printf/ft_printf.h"

int	ft_atoi(const char *nptr);
void ft_send_bits(int pid, char a);
void	ft_handler(int signal);
#endif