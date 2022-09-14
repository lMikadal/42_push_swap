/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:04:43 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/13 16:04:45 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_ra(t_list *lst, t_b_to_a *g)
{
	while (g->j < g->i)
	{
		if ((lst->s_b[0] < lst->s_a[0] \
			&& (lst->s_a[lst->size_a - 1] < g->start \
			|| lst->s_a[lst->size_a - 1] > g->end)) \
			|| (lst->s_b[0] < lst->s_a[0] \
			&& lst->s_b[0] > lst->s_a[lst->size_a - 1]))
		{
			ft_pa(lst, 1);
			break ;
		}
		else if ((lst->s_b[0] > lst->s_a[0] && lst->s_b[0] < lst->s_a[1]) \
				|| (lst->s_b[0] > lst->s_a[0] \
				&& (lst->s_a[1] < g->start || lst->s_a[1] > g->end)))
		{
			ft_ra(lst, 1);
			ft_pa(lst, 1);
			break ;
		}
		else
			ft_ra(lst, 1);
		g->j++;
	}
	if (lst->s_a[0] - lst->s_a[1] == 1)
		ft_sa(lst, 1);
}

void	ft_sort_rra(t_list *lst, int start, int end, int j)
{
	while (j < lst->size_a)
	{
		if ((lst->s_b[0] < lst->s_a[0] \
			&& (lst->s_a[lst->size_a - 1] < start \
			|| lst->s_a[lst->size_a - 1] > end))
			|| (lst->s_b[0] < lst->s_a[0] \
			&& lst->s_b[0] > lst->s_a[lst->size_a - 1]) \
			|| (lst->s_b[0] > lst->s_a[lst->size_a - 1] \
			&& (lst->s_a[0] < start || lst->s_a[0] > end)))
		{
			ft_pa(lst, 1);
			break ;
		}
		else if (lst->s_b[0] > lst->s_a[0] \
			&& (lst->s_a[1] < start || lst->s_a[1] > end))
		{
			ft_pa(lst, 1);
			ft_sa(lst, 1);
			break ;
		}
		else
			ft_rra(lst, 1);
		j++;
	}
}

void	ft_check_sort(t_list *lst, t_b_to_a *g)
{
	while (g->k < g->i && g->count != 0)
	{
		if (lst->s_b[0] > lst->s_a[lst->size_a - 1] \
			&& lst->s_b[0] < lst->s_a[0])
			g->count = 0;
		else if (lst->s_b[0] > lst->s_a[g->k] \
			&& lst->s_b[0] < lst->s_a[g->k + 1])
			g->count = 0;
		else if (lst->s_b[0] > lst->s_a[g->k] \
			&& (lst->s_a[g->k + 1] < g->start || lst->s_a[g->k + 1] > g->end))
			g->count = 0;
		g->k++;
	}
}

void	ft_b_to_a(t_list *lst, int start, int end)
{
	t_b_to_a	g;

	ft_init_b_to_a(&g, start, end, lst);
	while (lst->s_a[g.i] >= g.start && lst->s_a[g.i] <= g.end)
		g.i++;
	while (lst->s_a[g.j] >= g.start && lst->s_a[g.j] <= g.end)
		g.j--;
	if (g.j == lst->size_a - 1)
	{
		g.j = 0;
		ft_sort_ra(lst, &g);
	}
	else if (g.i == 1)
		ft_sort_rra(lst, g.start, g.end, g.j);
	else
	{
		ft_check_sort(lst, &g);
		if (g.count == 0)
		{
			g.j = 0;
			ft_sort_ra(lst, &g);
		}
		else
			ft_sort_rra(lst, g.start, g.end, g.j);
	}
}

void	ft_sort_mod(t_list *lst, int start, int end)
{
	if (start != 1)
	{
		ft_pa(lst, 1);
		if (lst->s_b[0] < lst->s_a[0])
			ft_pa(lst, 1);
		else
		{
			ft_pa(lst, 1);
			ft_sa(lst, 1);
		}
	}
	while (lst->size_b != 0)
		ft_b_to_a(lst, start, end);
}
