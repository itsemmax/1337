/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:21:10 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/22 11:21:42 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	last = *stack_a;
	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	while (last->next->next != NULL)
	{
		last = last->next;
	}
	tmp = last->next;
	last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	last = *stack_b;
	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	while (last->next->next != NULL)
	{
		last = last->next;
	}
	tmp = last->next;
	last->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
