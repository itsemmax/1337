/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:23:42 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/22 11:23:49 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	t_stack	*head;
	int		tmp_data;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	head = *stack_a;
	tmp_data = head->data;
	head->data = head->next->data;
	head->next->data = tmp_data;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack **stack_b)
{
	t_stack	*head;
	int		tmp_data;

	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	head = *stack_b;
	tmp_data = head->data;
	head->data = head->next->data;
	head->next->data = tmp_data;
	write(1, "sa\n", 3);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
	return (0);
}
