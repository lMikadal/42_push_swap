/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:45:00 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/15 01:29:54 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	list;

	if (ac == 1)
		exit(0);
	ft_init(&list);
	ft_loc_stack(ac, av, &list, 0);
	list.half_a = list.size_a / 2;
	ft_change_index(&list);
	if (list.size_a <= 3)
		ft_sort_3(&list);
	else if (list.size_a <= 5)
		ft_sort_5(&list);
	else if (list.size_a <= 10)
		ft_sort(&list, 3);
	else if (list.size_a <= 100)
		ft_sort(&list, 4);
	else
		ft_sort(&list, 10);
	free(list.s_a);
	free(list.s_b);
	return (0);
}
