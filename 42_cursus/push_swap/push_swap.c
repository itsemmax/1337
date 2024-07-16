#include "push_swap.h" 

char	**new_str(char **str)
{
	int		i;
	char	*new;
	char	**str1;

	i = 1;
	new = 0;
	if(str[i] == NULL)
		return(NULL);
	while (str[i])
	{
		new = ft_strjoin(new, str[i]);
		if (str[i + 1] != NULL)
			new = ft_strjoin(new, " ");
		i++;
	}
	str1 = ft_split(new, ' ');
	free(new);
	return (str1);
}

int	check_error(char **str)
{
	int	i;

	i = 0;
	if (check_double(str) != 0)
		return (0);
	while (str[i] != NULL)
	{
		if (!is_int(str[i]) || !check_digits(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_stack(t_stack *a, char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_lstadd_back(&a,ft_lstnew(ft_atoi(str[i])));
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char **str;

	stack_a = NULL;
	stack_b = NULL;

	if(argc > 1)
	{
		str = new_str(argv);
		if(str == NULL || !check_error(str))
		{
			write(2,"Error\n",6);
			if(str)
				free(str);
			return(0);
		}
		fill_stack(stack_a, str);
		while(stack_a)
		{
			printf("%d\n",stack_a->data);
			stack_a = stack_a->next;
		}
	}
	return(0);
}