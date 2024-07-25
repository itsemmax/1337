/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:23:59 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/25 17:37:17 by ichaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*fill_tab(int *tab, char **str, int size)
{
	int	i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (tab);
}

void	sorted_tab(int *tab, int x)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < x)
	{
		j = i + 1;
		while (j < x)
		{
			if (tab[i] > tab[j])
			{
				t = tab[i];
				tab[i] = tab[j];
				tab[j] = t;
			}
			j++;
		}
		i++;
	}
}

void	get_index(t_stack *a, int *t, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (t[i] == a->data)
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}
