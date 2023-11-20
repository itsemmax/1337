#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *head;

	head = NULL;
	head =(t_list *)malloc(sizeof(t_list));
	head->content = content;
	head->next = NULL;
	return(head);
}

/*#include<stdio.h>
#include<stdlib.h>

int main()
{
	t_list *p;
	int a;

	a = 42;
	p = ft_lstnew(&a);
	printf("%d",*(int *)p->content);
	free(p);
}*/