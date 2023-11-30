/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:34:26 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 20:33:50 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	node = ft_lstlast(*lst);
	if (!node)
	{
		*lst = new;
		return ;
	}
	node->next = new;
}
// #include<stdio.h>
// int main()
// {
// 	t_list *node;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	t_list *head;
// 	t_list *node4;
// 	node = ft_lstnew("hello");
// 	node1 = ft_lstnew("world");
// 	ft_lstadd_front(&node1,node);
// 	node2 = ft_lstnew("emma");
// 	ft_lstadd_back(&node1,node2);
// 	node3 = ft_lstnew("safae");
//     ft_lstadd_back(&node2,node3);
// 	printf("%d\n",ft_lstsize(node));
// 	head = node;
// 	while(head)
// 	{
// 		printf("%s ",head->content);
// 		head = head->next;
// 	}
// 	printf("\n");
// 	node4 = ft_lstlast(node);
// 	printf("%s\n",node4->content);
// }
