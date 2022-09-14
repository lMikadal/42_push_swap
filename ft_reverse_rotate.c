/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:32:31 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/04 13:32:33 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list *lst, int mode)
{
	int	i;
	int	temp;
	int	size;

	i = 0;
	temp = lst->s_a[lst->size_a - 1];
	size = lst->size_a;
	while (i < lst->size_a)
	{
		lst->s_a[size] = lst->s_a[size - 1];
		if (size - 1 == 0)
			break ;
		size--;
		i++;
	}
	lst->s_a[0] = temp;
	if (mode == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list *lst, int mode)
{
	int	i;
	int	temp;
	int	size;

	i = 0;
	temp = lst->s_b[lst->size_b - 1];
	size = lst->size_b;
	while (i < lst->size_b)
	{
		lst->s_b[size] = lst->s_b[size - 1];
		if (size - 1 == 0)
			break ;
		size--;
		i++;
	}
	lst->s_b[0] = temp;
	if (mode == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list *lst, int mode)
{
	ft_rra(lst, 0);
	ft_rrb(lst, 0);
	if (mode == 1)
		write(1, "rrr\n", 4);
}
