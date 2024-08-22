#include"philo.h"

int	ft_atoi(char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	sign = 1;
	res = 0;
	while(str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return(res * sign);
}
int	check_sign(int nbr)
{
	if(nbr < 0)
		return(0);
	else
		return(1);
}

int	check_digits(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return(0);
		i++;
	}
	return(1);
}