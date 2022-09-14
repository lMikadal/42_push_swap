/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:29:49 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/03 21:29:50 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *lst, int mode)
{
	ft_swap(&(lst->s_a[0]), &(lst->s_a[1]));
	if (mode == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list *lst, int mode)
{
	ft_swap(&(lst->s_b[0]), &(lst->s_b[1]));
	if (mode == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list *lst, int mode)
{
	ft_swap(&(lst->s_a[0]), &(lst->s_a[1]));
	ft_swap(&(lst->s_b[0]), &(lst->s_b[1]));
	if (mode == 1)
		write(1, "ss\n", 3);
}
