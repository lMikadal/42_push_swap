/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alogorithm_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:01:22 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/14 02:01:23 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_group(t_list *lst, int size)
{
	int	i;
	int	avg;

	i = 0;
	avg = lst->size_a / size;
	while (i < size)
	{
		if (i == 0)
		{
			lst->group[i][0] = 1;
			lst->group[i][1] = avg;
		}
		else if (size - i == 1)
		{
			lst->group[i][0] = lst->group[i - 1][1] + 1;
			lst->group[i][1] = lst->size_a;
		}
		else
		{
			lst->group[i][0] = lst->group[i - 1][1] + 1;
			lst->group[i][1] = lst->group[i - 1][1] + avg;
		}
		i++;
	}
}

void	ft_move_group(t_list *lst, int end, int chk)
{
	int	i;

	i = 0;
	while (lst->s_a[i] != end)
		i++;
	if (i <= lst->size_a / 2)
	{
		while (lst->s_a[chk] != end)
			ft_ra(lst, 1);
	}
	else
	{
		while (lst->s_a[chk] != end)
			ft_rra(lst, 1);
	}	
}

void	ft_sort_head(t_list *lst, int s)
{
	while (1)
	{
		if (lst->s_a[lst->size_a - 1] >= lst->group[s][0] \
			&& lst->s_a[lst->size_a - 1] <= lst->group[s][1])
		{
			ft_rra(lst, 1);
			ft_pb(lst, 1);
		}
		else if (lst->s_a[0] >= lst->group[s][0] \
			&& lst->s_a[0] <= lst->group[s][1])
			ft_pb(lst, 1);
		else
			ft_ra(lst, 1);
		if (lst->size_b == lst->group[s][1] - lst->group[s][0] + 1)
		{
			ft_sort_mod(lst, lst->group[s][0], lst->group[s][1]);
			break ;
		}
	}
	ft_move_group(lst, lst->group[s][1], lst->size_a - 1);
}

void	ft_sort_body(t_list *lst, int s)
{
	while (1)
	{
		if (lst->s_a[lst->size_a - 1] >= lst->group[s][0] \
			&& lst->s_a[lst->size_a - 1] <= lst->group[s][1])
		{
			ft_rra(lst, 1);
			ft_pb(lst, 1);
		}
		else if (lst->s_a[0] >= lst->group[s][0] \
			&& lst->s_a[0] <= lst->group[s][1])
			ft_pb(lst, 1);
		else
			ft_ra(lst, 1);
		if (lst->size_b == lst->group[s][1] - lst->group[s][0] + 1)
		{
			while (lst->s_a[0] != lst->group[s][1] + 1)
				ft_ra(lst, 1);
			ft_sort_mod(lst, lst->group[s][0], lst->group[s][1]);
			break ;
		}
	}
	ft_move_group(lst, lst->group[s][0], 0);
}

void	ft_sort_foot(t_list *lst, int s)
{
	while (1)
	{
		if (lst->s_a[1] - lst->s_a[0] == 1 \
			&& lst->temp_s_a != lst->s_a[0])
		{
			lst->temp_s_a = lst->s_a[0];
			lst->group[0][1] = lst->group[0][1] - 1;
		}
		else if (lst->s_a[0] >= lst->group[0][0] \
			&& lst->s_a[0] <= lst->group[0][1])
			ft_pb(lst, 1);
		else
			ft_rra(lst, 1);
		if (lst->s_a[lst->size_a - 2] == lst->group[s][1])
		{
			if (lst->s_a[0] < lst->s_a[lst->size_a - 1])
			{
				ft_rra(lst, 1);
				ft_sa(lst, 1);
			}
			ft_sort_mod(lst, lst->group[0][0], lst->group[0][1]);
			break ;
		}
	}
	ft_move_group(lst, lst->group[s][1], lst->size_a - 1);
}
