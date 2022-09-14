/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:56:21 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/14 14:56:35 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

static int	ft_cmp(char *cmd, char *s)
{
	int	i;
	int	len;

	len = ft_strlen(cmd);
	i = 0;
	while (i < len)
	{
		if (cmd[i] != s[i])
			return (0);
		i++;
	}
	return (1);
}

static void	ft_action(t_list *lst, char *cmd)
{
	if (ft_cmp(cmd, "sa\n") == 1)
		ft_sa(lst, 0);
	else if (ft_cmp(cmd, "sb\n") == 1)
		ft_sb(lst, 0);
	else if (ft_cmp(cmd, "ss\n") == 1)
		ft_ss(lst, 0);
	else if (ft_cmp(cmd, "pa\n") == 1)
		ft_pa(lst, 0);
	else if (ft_cmp(cmd, "pb\n") == 1)
		ft_pb(lst, 0);
	else if (ft_cmp(cmd, "ra\n") == 1)
		ft_ra(lst, 0);
	else if (ft_cmp(cmd, "rb\n") == 1)
		ft_rb(lst, 0);
	else if (ft_cmp(cmd, "rr\n") == 1)
		ft_rr(lst, 0);
	else if (ft_cmp(cmd, "rra\n") == 1)
		ft_rra(lst, 0);
	else if (ft_cmp(cmd, "rrb\n") == 1)
		ft_rrb(lst, 0);
	else if (ft_cmp(cmd, "rrr\n") == 1)
		ft_rrr(lst, 0);
}

int	main(int ac, char **av)
{
	t_list	list;
	char	*cmd;

	if (ac == 1)
		exit(0);
	ft_init(&list);
	ft_loc_stack(ac, av, &list, 1);
	ft_change_index(&list);
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		ft_action(&list, cmd);
		free(cmd);
	}
	if (ft_check_sort_a(&list, 1) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(list.s_a);
	free(list.s_b);
	return (0);
}
