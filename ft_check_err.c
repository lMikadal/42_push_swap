/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:22:13 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/03 14:22:16 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_digit(t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	while (lst->stack[i])
	{
		j = 0;
		while (lst->stack[i][j])
		{
			if (lst->stack[i][j] == '-')
			{
				if (lst->stack[i][j + 1] >= '0' && lst->stack[i][j + 1] <= '9')
					j++;
			}
			if (lst->stack[i][j] < '0' || lst->stack[i][j] > '9')
				ft_error(lst, 0);
			j++;
		}
		i++;
	}
}

void	ft_error(t_list *lst, int mode)
{
	ft_free_split(lst);
	if (mode == 1)
		free(lst->s_a);
	write(2, "Error\n", 6);
	exit(0);
}
