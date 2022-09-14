/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:58:27 by pmikada           #+#    #+#             */
/*   Updated: 2022/08/19 12:24:25 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char	**stack;
	int		*s_a;
	int		size_a;
	int		half_a;
	int		*s_b;
	int		size_b;
	int		i;
	int		j;
	int		temp;
	int		c;
	int		temp_s_a;
	int		group[9][2];
}	t_list;

typedef struct s_change_index
{
	long int	min;
	long int	temp_min;
	int			index;
	int			temp_index;
	int			i;
	int			j;
	int			*new;
}	t_change;

typedef struct s_b_to_a
{
	int	i;
	int	j;
	int	k;
	int	count;
	int	start;
	int	end;
}	t_b_to_a;

void	ft_check_stack(int ac, char **av, t_list *lst, int mode);
void	ft_add_stack(int ac, char **av, t_list *lst);
void	ft_loc_stack(int ac, char **av, t_list *lst, int m);
void	ft_check_digit(t_list *lst);
void	ft_error(t_list *lst, int mode);
char	**ft_split(char *s, char c);
void	ft_free_split(t_list *lst);
void	ft_init(t_list *lst);
int		ft_strlen(char *s);
int		ft_atoi(char *str, t_list *lst);
void	ft_swap(int *a, int *b);
void	ft_init_b_to_a(t_b_to_a *g, int start, int end, t_list *lst);
void	ft_change_index(t_list *lst);
void	ft_sa(t_list *lst, int mode);
void	ft_sb(t_list *lst, int mode);
void	ft_ss(t_list *lst, int mode);
void	ft_pa(t_list *lst, int mode);
void	ft_pb(t_list *lst, int mode);
void	ft_ra(t_list *lst, int mode);
void	ft_rb(t_list *lst, int mode);
void	ft_rr(t_list *lst, int mode);
void	ft_rra(t_list *lst, int mode);
void	ft_rrb(t_list *lst, int mode);
void	ft_rrr(t_list *lst, int mode);
int		ft_check_sort_a(t_list *lst, int chk);
void	ft_sort_3(t_list *lst);
void	ft_sort_5(t_list *lst);
void	ft_sort(t_list *lst, int size);
void	ft_sort_ra(t_list *lst, t_b_to_a *g);
void	ft_sort_rra(t_list *lst, int start, int end, int j);
void	ft_check_sort(t_list *lst, t_b_to_a *g);
void	ft_b_to_a(t_list *lst, int start, int end);
void	ft_sort_mod(t_list *lst, int start, int end);
void	ft_group(t_list *lst, int size);
void	ft_move_group(t_list *lst, int end, int chk);
void	ft_sort_head(t_list *lst, int s);
void	ft_sort_body(t_list *lst, int s);
void	ft_sort_foot(t_list *lst, int s);

#endif
