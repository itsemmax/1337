/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:58:19 by ichaoub           #+#    #+#             */
/*   Updated: 2023/11/30 20:35:34 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// #include<stdio.h>
// int main()
// {
// 	t_list	*node;
// 	node = ft_lstnew((char *) "hello world");
// 	if(!node)
// 		printf("the allocation failled");
// 	else
// 		printf("%s",node->content);
// 	free(node);

// }