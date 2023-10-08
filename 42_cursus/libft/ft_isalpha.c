/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:28:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/08 17:28:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static	int	ft_isupper(int c)
{
	if(c >= 'A' && c <= 'Z')
		return (1);
	return(0);
}

static int ft_islower(int c)
{
	if(c >= 'a' && c <= 'z')
		return(1);
	return (0);
}
int	ft_isalpha(int c)
{
	if(ft_isupper(c) || ft_islower(c))
		return(1);
	return (0);
}
*/
int	ft_isalpha(int c)
{
	return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}