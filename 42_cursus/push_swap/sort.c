#include "push_swap.h"

void sort_2(t_stack **a)
{
	sa(a);
}
void sort_3(t_stack **a)
{
	t_stack *c;
	t_stack *d;

	c = (*a)->next;
	d =(*a)->next->next;
	if ((*a)->data > c->data && (*a)->data < d->data && c->data < d->data)
		sa(a);
	if ((*a)->data > c->data && (*a)->data > d->data && c->data < d->data)
		ra(a);
	if ((*a)->data < c->data && (*a)->data > d->data && c->data > d->data)
		rra(a);
	if ((*a)->data < c->data && (*a)->data < d->data && c->data > d->data)
	{
		sa(a);
		ra(a);
	}
	if ((*a)->data > c->data && (*a)->data > d->data && c->data > d->data)
	{
		sa(a);
		rra(a);
	}
}
// void	sort_5(t_stack **a,t_stack **b);
void sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sort_2(a);
	if (ft_lstsize(*a) == 3)
		sort_3(a);
	// if(ft_lstsize(*a) == 5)
	// 	sort_5(a,b);
}