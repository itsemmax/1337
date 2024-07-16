#include "push_swap.h"

int		pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	if(ft_lstsize(*stack_b) == 0)
		return(-1);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a,tmp);
	write(1,"pa\n",3);
	return (0);
}
int		pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	if(ft_lstsize(*stack_a) == 0)
		return(-1);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b,tmp);
	write(1,"pb\n",3);
	return (0);
}