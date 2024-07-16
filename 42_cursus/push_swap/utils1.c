#include "push_swap.h"

int check_digits(char *str)
{
	int i;

	i = 0;
	if( str[i] == '+' || str[i] == '-')
	{
		i++;
	}
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	is_int(char *s)
{
	long	n;

	n = ft_atoi(s);
	if (n > (long)(2147483647) || n < (long)(-2147483648))
		return (0);
	return (1);
}

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while((str[i] <= 13 && str[i] >= 9) || (str[i] == ' '))
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return(res * sign);
}

int	check_double(char **str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if(ft_atoi(str[i])== ft_atoi(str[j]))
				return(0);
			j++;
		}
		i++;
	}
	return(1);
}