#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	t_stack head;
	int i;

	i = 0;
	if(!lst)
		return(NULL);
	head = lst;
	while(head)
	{
		head = head->next;
		i++;
	}
	return(i);
}

t_stack	*ft_lstnew(int *content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if(!node)
		return(NULL);
	node->data = data;
	node->next = NULL;
	return(node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if(!lst)
		return(NULL);
	while(lst)
		lst = lst->next;
	return(lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

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