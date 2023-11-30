/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:48:40 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 20:35:46 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*head;
	int		count;

	count = 0;
	head = lst;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}
// #include<stdio.h>
// int main()
// {
// 	t_list *head;
// 	t_list *node;
// 	t_list *node1;
// 	t_list *node2;

// 	node = ft_lstnew("hello");
// 	node1 = ft_lstnew("world");
// 	node2 = ft_lstnew("emma");
// 	node1->next = node2;
// 	node->next = node1;
// 	node2->next = NULL;
// 	printf("%d",ft_lstsize(node));
// 	free(node);
// 	free(node1);
// 	free(node2);
// }