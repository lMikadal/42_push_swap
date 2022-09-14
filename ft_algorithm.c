/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:11:50 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/04 14:11:53 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort_a(t_list *lst, int chk)
{
	int	i;

	i = 0;
	while (i < lst->size_a)
	{
		if (lst->s_a[i] > lst->s_a[i + 1] && i + 1 < lst->size_a)
			return (-1);
		if (lst->size_b != 0 && chk == 1)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_sort_3(t_list *lst)
{
	if (lst->s_a[0] > lst->s_a[1] && lst->size_a == 2)
		ft_sa(lst, 1);
	else if (lst->s_a[0] == 1 && lst->s_a[1] == 3)
	{
		ft_rra(lst, 1);
		ft_sa(lst, 1);
	}
	else if (lst->s_a[0] == 2 && lst->s_a[1] == 1)
		ft_sa(lst, 1);
	else if (lst->s_a[0] == 2 && lst->s_a[1] == 3)
		ft_rra(lst, 1);
	else if (lst->s_a[0] == 3 && lst->s_a[1] == 1)
		ft_ra(lst, 1);
	else if (lst->s_a[0] == 3 && lst->s_a[1] == 2)
	{
		ft_sa(lst, 1);
		ft_rra(lst, 1);
	}
}

void	ft_sort_5(t_list *lst)
{
	int	i;

	i = -1;
	while (ft_check_sort_a(lst, 1) != 1)
	{
		if (lst->size_a + lst->size_b == 5 && lst->s_a[0] <= 2)
			ft_pb(lst, 1);
		else if (lst->size_a + lst->size_b == 4 && lst->s_a[0] == 1)
			ft_pb(lst, 1);
		if (lst->size_a == 3)
		{
			ft_change_index(lst);
			ft_sort_3(lst);
			if (lst->size_b == 2 && lst->s_b[0] < lst->s_b[1])
				ft_sb(lst, 1);
			while (++i <= lst->size_b)
				ft_pa(lst, 1);
			return ;
		}
		if (lst->size_a + lst->size_b == 5 && lst->s_a[0] > 2)
			ft_ra(lst, 1);
		else if (lst->size_a + lst->size_b == 4 && lst->s_a[0] != 1)
			ft_ra(lst, 1);
	}
}

void	ft_sort(t_list *lst, int size)
{
	int	i;

	if (ft_check_sort_a(lst, 1) == 1)
		return ;
	ft_group(lst, size);
	i = 0;
	while (i < size && ft_check_sort_a(lst, 1) != 1)
	{
		if (i == 0)
			ft_sort_head(lst, size - 1);
		else if (i == size - 1)
			ft_sort_foot(lst, size - 1);
		else
			ft_sort_body(lst, size - i - 1);
		i++;
	}
}
