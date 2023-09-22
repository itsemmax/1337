#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * sign);
}

int main() {
	printf("%d\n",ft_atoi("   -123456zuadbz"));
	printf("%d\n",atoi("   -123456zuadbz"));
}