#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	t;

	i = 0;
	sign = 1;
	t = 0;
	while (nptr[i] == ' ' || ((nptr[i] >= 9) && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		t = t * 10 + (nptr[i] - 48);
		i++;
	}
	return (t * sign);
}

int	str_isdigit(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= 0 && str[i] <= 9)
			return(1);
		i++;
	}
	return(0);
}