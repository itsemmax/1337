#include "philo.h"

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if(argc == 5 || argc == 6)
	{
		while(argv[i])
		{
			printf("%s ", argv[i]);
			if((ft_atoi(argv[1]) == 0 || ft_atoi(argv[1]) > 200 ) || !check_sign(ft_atoi(argv[i])) || !check_digits(argv[i]))
			{
				printf("urs args is not valid");
				exit(1);
			}
			i++;
		}
	}
	else
	{
		printf("please enter 4 or 5 args");
		exit(1);
	}
}
