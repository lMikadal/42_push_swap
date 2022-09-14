/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 13:11:28 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/04 13:11:30 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list *lst, int mode)
{
	int	i;
	int	temp;
	int	size;

	i = 0;
	temp = lst->s_a[0];
	size = lst->size_a;
	while (i < lst->size_a)
	{
		lst->s_a[i] = lst->s_a[i + 1];
		if (i + 1 == size)
			break ;
		i++;
	}
	lst->s_a[i] = temp;
	if (mode == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list *lst, int mode)
{
	int	i;
	int	temp;
	int	size;

	i = 0;
	temp = lst->s_b[0];
	size = lst->size_b;
	while (i < lst->size_b)
	{
		lst->s_b[i] = lst->s_b[i + 1];
		if (i + 1 == size)
			break ;
		i++;
	}
	lst->s_b[i] = temp;
	if (mode == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list *lst, int mode)
{
	ft_ra(lst, 0);
	ft_rb(lst, 0);
	if (mode == 1)
		write(1, "rr\n", 3);
}
