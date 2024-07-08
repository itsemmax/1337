#include "push_swap.h"

int	swap(t_stack **stack_a)
{
	t_stack *head;
	int tmp_data;
	int tmp_next;

	if(ft_lstsize(*stack_a) < 2)
		return (-1);
	head = *stack_a
	tmp_data = head->data;
	head->data = head->next->data;
	head->next->data = tmp_data;
	return(0);
}

int		sa(t_stack **stack_a)
{
	if(swap(stack_a) == -1)
		return(-1);
	write(1,"sa\n",3);
	return(0);
}

int		sb(t_stack **stack_b)
{
	if(swap(stack_b) == -1)
		return(-1);
	write(1,"sb\n",3);
	return(0);
}

int		ss(t_stack *stack_a, t_stack *stack_b)
{
	if(ft_ls)
}