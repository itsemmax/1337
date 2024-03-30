#include "minitalk.h"

void	ft_handler(int signal)
{
	static int bit;
	static int t;

	if(signal = SIGUSR2)
		t |= 0x01 << bit;
	bit++;
	if(bit == 8)
	{
		ft_printf("%c",t);
		bit = 0;
		t = 0;
	}
}

int main()
{
	int pid;

	pid = getpid();
	ft_printf("pid :%i\n",pid);
	signal(SIGUSR1,ft_handler);
	signal(SIGUSR2,ft_handler);
	pause();
	return(0);
}