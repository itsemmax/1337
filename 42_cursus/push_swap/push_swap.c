#include "push_swap.h"

char **new_str(char **str)
{
	int i;
	char *new;
	char **str1;

	i = 1;
	new = "";
	if (str[i] == NULL)
		return (NULL);
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

int check_error_dig(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		if (!is_int(str[i]) || !check_digits(str[i]) || !check_sign(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void fill_stack(t_stack **a, char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
}
int is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while(a->next)
	{
		if(a->data > a->next->data)
			return(0);
		a = a->next;
	}
	return(1);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **str;
	int *tab;

	stack_a = NULL;
	stack_b = NULL;

	if (argc > 1)
	{
		str = new_str(argv);
		if (str == NULL || !check_error_dig(str) || !check_double(str))
		{
			write(2, "Error\n", 6);
			if (str)
				free(str);
				//free_str(str);
			return (0);
		}
		tab = fill_tab(tab,str,split_len(str));
		sorted_tab(tab);
		fill_stack(&stack_a, str);
		get_indice(stack_a,tab);
		if(!is_sorted(stack_a))
			sort(&stack_a,&stack_b,tab);
		int j = 0;
		while (stack_a && tab[j])
		{
			printf("%d = %d\n", tab[j], stack_a->indice);
			stack_a = stack_a->next;
			j++;
		}
		//free_stack(a,b);
		return(0);
	}
	return (0);
}
