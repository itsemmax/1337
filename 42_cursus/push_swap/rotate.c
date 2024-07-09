#include "push_swap.h"

int		ra(t_stack **stack_a)
{
	t_stack	last;
	t_stack head;

	if(ft_lstsize(&stack_a) < 2)
		return(-1);
	head = *stack_a;
	last = ft_lstlast(&stack_a);
	*stack_a = head->next;
	head->next = NULL;
	last->next = head;
	write(1,"ra\n",1);
}
int		rb(t_stack **stack_b)
{
	t_stack	last;
	t_stack head;

	if(ft_lstsize(&stack_b) < 2)
		return(-1);
	head = *stack_b;
	last = ft_lstlast(&stack_b);
	*stack_b = head->next;
	head->next = NULL;
	last->next = head;
	write(1,"rb\n",1);
}
int		rr(t_stack **stack_a, t_stack **stack_b)
{
	if(ft_lstsize(&stack_a) < 2 || ft_lstsize(&stack_b) < 2)
		return(-1);
	ra(stack_a);
	rb(stack_b);
	write(1,"rr\n",3);
}


