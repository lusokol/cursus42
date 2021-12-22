/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:06 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/22 17:44:16 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_nbr
{
	int				nbr;
	int				index;
	int				move;
	int				move_a;
	int				move_b;
	int				sens;
	int				sens_a;
	int				push_b;
	struct s_nbr	*next;
}	t_nbr;

typedef struct s_backtrack
{
	int					in_a;
	int					in_b;
	int					*actual;
	struct s_backtrack	**tab;
}	t_backtrack;

typedef struct s_sort
{
	t_nbr	*a;
	t_nbr	*b;
}	t_sort;

typedef struct s_plsc
{
	int	lm;
	int	m;
	int	*tab;
	int	*s;
	int	max;
}	t_plsc;

typedef struct s_all
{
	int			iteration_max;
	int			print;
	int			size;
	int			ac;
	char		**tab;
	int			*nbr;
	t_sort		*original;
	t_sort		*qs;
	t_nbr		*copy;
	t_backtrack	*first;
	int			*result;
}	t_all;

void		free_plssc(t_plsc *plsc, int *tab);
int			*lst_to_tab(t_nbr *a, t_plsc *plsc);
void		init_tabs(int **l, t_plsc *plsc);
void		fill_tab(int *tab, int n, int value);
t_nbr		*cp_lst(t_all *all);
void		ft_fct_silent(t_nbr **a, t_nbr **b, int fct);
int			*check_iter(t_all *all, int iter, t_backtrack *bt);
int			free_sort(t_nbr *a, t_nbr *b);
int			check_new(int a, int b, t_backtrack *tmp);
void		last_rotation(t_sort *tmp);
void		best_move(t_sort *tmp);
void		push_b(t_sort *tmp);
void		find_higher(int i, t_nbr *a, t_nbr *b);
void		calc_up_a(t_sort *lst);
void		calc_up_b(t_sort *lst);
t_all		*lst_init(int ac, char **av);
int			check_arg(int ac, char **av);
void		create_lst(t_all *all);
int			check_double(t_nbr *lst);
int			check_nb_arg(t_all *all);
void		ft_free_all(t_all *lst);
t_nbr		*ft_lstnew2(int nbr, int index);
void		ft_lstadd_back2(t_nbr **alst, t_nbr *new);
void		ft_lst_free(t_nbr *lst);
void		ft_lst_sort(t_nbr *lst);
void		ft_swap_lst(t_nbr *lst1, t_nbr *lst2);
void		ft_take_index(t_all *all);
int			ft_backtrack(t_all *all, int iter);
t_backtrack	*new_bt(int *actual, int i);
void		ft_print_lst(t_all *all);
int			partition(int l, int h, t_all *all);
void		logic_sort(t_all *all);
void		ft_quick_sort(int l, int h, t_all *all);
void		ft_fct(t_sort *all, int fct, int print);

void		ft_sa(t_nbr **a, t_nbr **b, int print);
void		ft_sb(t_nbr **a, t_nbr **b, int print);
void		ft_ss(t_nbr **a, t_nbr **b, int print);
void		ft_pa(t_nbr **a, t_nbr **b, int print);
void		ft_pb(t_nbr **a, t_nbr **b, int print);
void		ft_ra(t_nbr **a, t_nbr **b, int print);
void		ft_rb(t_nbr **a, t_nbr **b, int print);
void		ft_rr(t_nbr **a, t_nbr **b, int print);
void		ft_rra(t_nbr **a, t_nbr **b, int print);
void		ft_rrb(t_nbr **a, t_nbr **b, int print);
void		ft_rrr(t_nbr **a, t_nbr **b, int print);

void		ft_ssa(t_nbr **a, t_nbr **b);
void		ft_ssb(t_nbr **a, t_nbr **b);
void		ft_sss(t_nbr **a, t_nbr **b);
void		ft_spa(t_nbr **a, t_nbr **b);
void		ft_spb(t_nbr **a, t_nbr **b);
void		ft_sra(t_nbr **a, t_nbr **b);
void		ft_srb(t_nbr **a, t_nbr **b);
void		ft_srr(t_nbr **a, t_nbr **b);
void		ft_srra(t_nbr **a, t_nbr **b);
void		ft_srrb(t_nbr **a, t_nbr **b);
void		ft_srrr(t_nbr **a, t_nbr **b);

#endif