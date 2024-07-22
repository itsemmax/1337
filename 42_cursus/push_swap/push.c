/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:20:11 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/22 11:21:03 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_b) == 0)
		return (-1);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_a) == 0)
		return (-1);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	write(1, "pb\n", 3);
	return (0);
}
