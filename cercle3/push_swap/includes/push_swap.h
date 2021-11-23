/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:06 by macbookpro        #+#    #+#             */
/*   Updated: 2021/11/08 16:54:33 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_nbr
{
	int				nbr;
	int				index;
	struct s_nbr	*next;
}	t_nbr;

typedef struct s_backtrack
{
	int					in_a;
	int					in_b;
	int					*actual;
	struct s_backtrack	**tab;
}	t_backtrack;

typedef struct s_all
{
	int			iteration_max;
	int			print;
	int			size;
	t_nbr		*a;
	t_nbr		*b;
	t_nbr		*copy;
	t_backtrack	*first;
	int			*result;
}	t_all;

t_nbr	*ft_lstnew2(int nbr, int index);
void	ft_lstadd_back2(t_nbr **alst, t_nbr *new);
void	ft_lst_free(t_nbr *lst);
void	ft_lst_sort(t_nbr *lst);
void	ft_swap_lst(t_nbr *lst1, t_nbr *lst2);
void	ft_take_index(t_all *all);
//int		ft_backtrack(t_all *all, int iter, int grid[100]);
int		ft_backtrack(t_all *all, int iter);
t_backtrack	*new_bt(int *actual, int i);
void	ft_sa(t_all *all);
void	ft_sb(t_all *all);
void	ft_ss(t_all *all);
void	ft_pa(t_all *all);
void	ft_pb(t_all *all);
void	ft_ra(t_all *all);
void	ft_rb(t_all *all);
void	ft_rr(t_all *all);
void	ft_rra(t_all *all);
void	ft_rrb(t_all *all);
void	ft_rrr(t_all *all);

void	ft_ssa(t_nbr **a, t_nbr **b);//1
void	ft_ssb(t_nbr **a, t_nbr **b);//2
void	ft_sss(t_nbr **a, t_nbr **b);//3
void	ft_spa(t_nbr **a, t_nbr **b);//4
void	ft_spb(t_nbr **a, t_nbr **b);//5
void	ft_sra(t_nbr **a, t_nbr **b);//6
void	ft_srb(t_nbr **a, t_nbr **b);//7
void	ft_srr(t_nbr **a, t_nbr **b);//8
void	ft_srra(t_nbr **a, t_nbr **b);//9
void	ft_srrb(t_nbr **a, t_nbr **b);//10
void	ft_srrr(t_nbr **a, t_nbr **b);//11

void	sort_two(t_all *all);
void	sort_three(t_all *all);
void	sort_four(t_all *all);
void	sort_five(t_all *all);


#endif


/*
logique
213658 sa
123658 pb pb pb
658 321 sa
568 321 pa pa pa
123568

tout mettre dans b
213658 ra
136582 pb
36582 1 rra
23658 1 pb pb
658 321 ra
586 321 pb
86 5321 ra
68 5321 pa pa pa pa
123568

index
213658 sa
123658 ra ra ra
658123 sa
568123 rra rra rra


*/