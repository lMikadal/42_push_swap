/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:59:18 by pmikada           #+#    #+#             */
/*   Updated: 2022/08/18 11:16:56 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_list *lst)
{
	lst->stack = NULL;
	lst->size_a = 0;
	lst->half_a = 0;
	lst->size_b = 0;
	lst->i = 1;
	lst->j = 0;
	lst->temp = 0;
	lst->c = 0;
	lst->temp_s_a = 0;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(char *str, t_list *lst)
{
	int			i;
	int			m;
	long int	sum;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	m = 1;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	if (sum * m > 2147483647 || sum * m < -2147483648)
		ft_error(lst, 1);
	return ((int)(sum * m));
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_init_b_to_a(t_b_to_a *g, int start, int end, t_list *lst)
{
	g->start = start;
	g->end = end;
	g->i = 0;
	g->j = lst->size_a - 1;
	g->k = 0;
	g->count = 1;
}
