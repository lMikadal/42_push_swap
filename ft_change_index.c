/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 21:18:22 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/04 21:18:24 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_c(t_change *lst)
{
	lst->i = 1;
	lst->temp_min = -2147483649;
	lst->temp_index = 0;
}

static void	ft_cpy(t_change *c, t_list *lst)
{
	int	i;

	i = 0;
	while (i < lst->size_a)
	{
		lst->s_a[i] = c->new[i];
		i++;
	}
	free(c->new);
}

void	ft_change_index(t_list *lst)
{
	t_change	c;

	ft_init_c(&c);
	c.new = (int *)malloc(sizeof(int) * lst->size_a);
	if (c.new == NULL)
		exit(0);
	while (c.i <= lst->size_a)
	{
		c.j = 0;
		c.min = 2147483648;
		while (c.j < lst->size_a)
		{
			if (c.min > lst->s_a[c.j] && lst->s_a[c.j] > c.temp_min)
			{
				c.min = lst->s_a[c.j];
				c.index = c.j;
			}
			c.j++;
		}
		c.new[c.index] = c.i;
		c.temp_min = c.min;
		c.temp_index = c.index;
		c.i++;
	}
	ft_cpy(&c, lst);
}
