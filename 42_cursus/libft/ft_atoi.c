#include"libft.h"
int ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int t;
	
	i = 0;
	sign = 1;
	while(nptr[i] == ' ' || nptr[i] == '\t')
	{
		i++;
	}
	if(nptr[i] == '-' || nptr[i] == '+')
	{
		if(nptr[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while(nptr[i] >= '0' && nptr[i] <= '9')
	{
		t = t * 10 + (nptr[i] - 48);
		i++;
	}
	return(t * sign);
}
