/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:42:34 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/14 15:42:45 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_stack(int ac, char **av, t_list *lst, int mode)
{
	lst->i = 1;
	while (lst->i < ac)
	{
		if (av[lst->i][0] == 0 && mode == 0)
			exit(0);
		if (av[lst->i][0] == 0 && mode == 1)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		lst->stack = ft_split(av[lst->i], ' ');
		lst->j = 0;
		ft_check_digit(lst);
		while (lst->stack[lst->j])
		{
			lst->size_a++;
			lst->j++;
		}
		ft_free_split(lst);
		lst->i++;
	}
}

void	ft_add_stack(int ac, char **av, t_list *lst)
{
	lst->i = 1;
	lst->size_a = 0;
	while (lst->i < ac)
	{
		lst->stack = ft_split(av[lst->i], ' ');
		lst->j = 0;
		while (lst->stack[lst->j])
		{
			lst->temp = ft_atoi(lst->stack[lst->j++], lst);
			lst->c = 0;
			while (lst->c < lst->size_a)
			{
				if (lst->s_a[lst->c] == lst->temp)
					ft_error(lst, 1);
				lst->c++;
			}
			lst->s_a[lst->size_a++] = lst->temp;
		}
		ft_free_split(lst);
		lst->i++;
	}
}

void	ft_loc_stack(int ac, char **av, t_list *lst, int m)
{
	ft_check_stack(ac, av, lst, m);
	lst->s_a = (int *)malloc(sizeof(int) * lst->size_a);
	if (lst->s_a == NULL)
		exit(0);
	ft_add_stack(ac, av, lst);
	lst->s_b = (int *)malloc(sizeof(int) * lst->size_a);
	if (lst->s_a == NULL)
		exit(0);
}
