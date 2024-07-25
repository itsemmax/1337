/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:19:56 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/25 19:52:51 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					is_int(char *s);
int					check_digits(char *str);
int					check_double(char **str);
int					ft_strlen(const char *s);
long				ft_atoi(char *str);
int					check_sign(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char const *s, char c);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
char				**new_str(char **str);
int					check_error_dig(char **str);
void				fill_stack(t_stack **a, char **str);
int					is_sorted(t_stack *a);
void				sort(t_stack **a, t_stack **b, int *t);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_4(t_stack **a, t_stack **b);
void				sort_5(t_stack **a, t_stack **b);
int					get_min(t_stack *a);
int					ft_pos(t_stack *a, int min);
int					*fill_tab(int *tab, char **str, int size);
void				sorted_tab(int *tab, int x);
int					split_len(char **str);
void				get_index(t_stack *a, int *t, int x);
void				free_array(char **str);
void				free_stacks(t_stack *stack_a, t_stack *stack_b);
void				handle_error(char **str);
char				*ft_strdup(char *s);
void				big_sort(t_stack **a, t_stack **b, int *t, int ch);
void				push_all_to_b(t_stack **a, t_stack **b, int ch);
void				push_all_to_a(t_stack **a, t_stack **b);
void				check_index(t_stack **a, int i, int ch);
int					ft_pos_i(t_stack *b, int top);

int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);
#endif
