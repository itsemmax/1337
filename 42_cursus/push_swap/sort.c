/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:23:25 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/22 11:23:31 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	sa(a);
}

void	sort_3(t_stack **a)
{
	t_stack	*c;
	t_stack	*d;

	c = (*a)->next;
	d = (*a)->next->next;
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

void	sort_4(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	while (ft_pos(*a, min))
	{
		if (ft_pos(*a, min) < ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = get_min(*a);
		while (ft_pos(*a, min))
		{
			if (ft_pos(*a, min) < ft_lstsize(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a);
	while (ft_lstsize(*b) > 0)
		pa(a, b);
}

void	sort(t_stack **a, t_stack **b, int *t)
{
	(void)*t;
	if (ft_lstsize(*a) == 2)
		sort_2(a);
	if (ft_lstsize(*a) == 3)
		sort_3(a);
	if (ft_lstsize(*a) == 4)
		sort_4(a, b);
	if (ft_lstsize(*a) == 5)
		sort_5(a, b);
}
