#ifndef	PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include<stdio.h>


typedef struct s_stack
{
	int	data;
	struct s_stack	*next;
}t_stack;

int		is_int(char *s);
int		check_digits(char *str);
long	int_check(long result);
int		check_double(char **str);
int		ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**new_str(char **str);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstnew(int *content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack *stack_a, t_stack *stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);
#endif
