#include "push_swap.h"

int	get_min(t_stack *a)
{
	int min;

	min = a->data;
	while(a)
	{
		if(a->data < min)
			min = a->data;
		a = a->next;
	}
	return(min);
}
int	ft_pos(t_stack *a,int min)
{
	int pos;

	pos = 0;
	while(a->data !=min)
	{
		pos++;
		a = a->next;
	}
	return(pos);
}