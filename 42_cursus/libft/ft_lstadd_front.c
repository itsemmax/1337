/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:22:20 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 20:35:10 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include<stdio.h>
// int main()
// {
// 	t_list	*node;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *head;
// 	node = ft_lstnew("hello");
// 	node2 = ft_lstnew("emma");
// 	ft_lstadd_front(&node,node2);
// 	head = node;
// 	while(head)
// 	{
// 		printf("%s\n",head->content);
// 		head = head->next;
// 	}
// 	free(node);
// 	free(node1);
// 	free(node2);
// }