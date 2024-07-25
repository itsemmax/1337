/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 03:18:47 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/25 19:51:26 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_i(t_stack *b, int top)
{
	int	pos;

	pos = 0;
	while (b->index != top)
	{
		pos++;
		b = b->next;
	}
	return (pos);
}

void	check_index(t_stack **a, int i, int ch)
{
	int		j;
	t_stack	*t;

	j = 0;
	t = *a;
	while (t)
	{
		if ((t)->index <= i || (t)->index <= i + ch)
			break ;
		j++;
		t = (t)->next;
	}
	if (j < ft_lstsize(*a) / 2)
		ra(a);
	else
		rra(a);
}

void	push_all_to_b(t_stack **a, t_stack **b, int ch)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_lstsize(*a);
	while (j < size)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
			j++;
		}
		else if ((*a)->index <= i + ch)
		{
			pb(a, b);
			i++;
			j++;
		}
		else
			check_index(a, i, ch);
	}
}

void	push_all_to_a(t_stack **a, t_stack **b)
{
	int	top_i;

	top_i = 0;
	while (*b)
	{
		top_i = ft_lstsize(*b) - 1;
		while (top_i != (*b)->index)
		{
			if (ft_pos_i(*b, top_i) < ft_lstsize(*b) / 2)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}

void	big_sort(t_stack **a, t_stack **b, int *t, int ch)
{
	int	i;

	i = ft_lstsize(*a);
	sorted_tab(t, i);
	get_index(*a, t, i);
	push_all_to_b(a, b, ch);
	push_all_to_a(a, b);
}
