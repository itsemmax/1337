/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaoub <ichaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:23:59 by ichaoub           #+#    #+#             */
/*   Updated: 2024/07/22 11:24:23 by ichaoub          ###   ########.fr       */
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

void	sorted_tab(int *tab)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
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

void	get_indice(t_stack *a, int *t)
{
	int	i;

	while (a)
	{
		i = 0;
		while (t[i])
		{
			if (t[i] == a->data)
			{
				a->indice = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}
