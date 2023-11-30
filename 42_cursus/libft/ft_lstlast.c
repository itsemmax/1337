/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:00:01 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 20:35:22 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
// #include<stdio.h>

// int main()
// {
// 	t_list *node;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;
// 	node = ft_lstnew("hello");
// 	node1 = ft_lstnew("world");
// 	node2= ft_lstnew("emma");
// 	node->next=node1;
// 	node1->next=node2;
// 	node2->next=NULL;

// 	node3 = ft_lstlast(node);
// 	printf("%s",node3->content);
// 	free(node);
// 	free(node1);
// 	free(node2);
// }