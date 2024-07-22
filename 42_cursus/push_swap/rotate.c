/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:21:54 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/22 11:22:33 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*head;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	head = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = head->next;
	head->next = NULL;
	last->next = head;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*head;

	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	head = *stack_b;
	last = ft_lstlast(*stack_b);
	*stack_b = head->next;
	head->next = NULL;
	last->next = head;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
