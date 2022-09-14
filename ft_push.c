/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:46:00 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/04 00:46:03 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_move(int size, int *arr)
{
	int	i;
	int	temp;

	i = 0;
	temp = size;
	while (i < size)
	{
		arr[temp] = arr[temp - 1];
		if (temp == 0)
			break ;
		temp--;
		i++;
	}
}

static void	ft_push_del(int size, int *arr)
{
	int	i;
	int	temp;

	i = 0;
	temp = size;
	while (i < size)
	{
		arr[i] = arr[i + 1];
		if (temp == 0)
			break ;
		temp--;
		i++;
	}
}

void	ft_pa(t_list *lst, int mode)
{
	ft_push_move(lst->size_a, lst->s_a);
	lst->s_a[0] = lst->s_b[0];
	lst->size_a += 1;
	lst->size_b -= 1;
	ft_push_del(lst->size_b, lst->s_b);
	if (mode == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_list *lst, int mode)
{
	ft_push_move(lst->size_b, lst->s_b);
	lst->s_b[0] = lst->s_a[0];
	lst->size_b += 1;
	lst->size_a -= 1;
	ft_push_del(lst->size_a, lst->s_a);
	if (mode == 1)
		write(1, "pb\n", 3);
}
