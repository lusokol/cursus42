/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:03:24 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/25 17:54:17 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fct_silent(t_nbr **a, t_nbr **b, int fct)
{
	if (fct == 1)
		ft_ssa(a, b);
	else if (fct == 2)
		ft_ssb(a, b);
	else if (fct == 3)
		ft_sss(a, b);
	else if (fct == 4)
		ft_spa(a, b);
	else if (fct == 5)
		ft_spb(a, b);
	else if (fct == 6)
		ft_sra(a, b);
	else if (fct == 7)
		ft_srb(a, b);
	else if (fct == 8)
		ft_srr(a, b);
	else if (fct == 9)
		ft_srra(a, b);
	else if (fct == 10)
		ft_srrb(a, b);
	else if (fct == 11)
		ft_srrr(a, b);
}

t_nbr	*cp_lst(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	tmp = all->a;
	lst = NULL;
	while (tmp)
	{
		ft_lstadd_back2(&lst, ft_lstnew2(tmp->nbr, tmp->index));
		tmp = tmp->next;
	}
	return (lst);
}

void	free_sort(t_nbr *a, t_nbr *b)
{
	if (a)
		ft_lst_free(a);
	if (b)
		ft_lst_free(b);
}

int	check_sort(t_all *all, int grid[100])
{
	t_nbr	*a;
	t_nbr	*b;
	t_nbr	*tmp;
	int		i;

	a = cp_lst(all);
	b = NULL;
	i = 0;
	while (grid[i])
		ft_fct_silent(&a, &b, grid[i++]);
	if (b)
	{
		free_sort(a, b);
		return (0);
	}
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
		{
			free_sort(a, b);
			return (0);
		}
		tmp = tmp->next;
	}
	free_sort(a, b);
	return (1);
}

int	check_len(int tab1[100], int tab2[100])
{
	int	i;

	i = 0;
	if (!tab1[0])
		return (1);
	while (i < 100)
	{
		if (tab1[i] == 0)
			return (0);
		else if (tab2[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

/*void	add_grid(t_all *all, int fct)
{
	int	i;

	i = 0;
	while (all->actual[i] != 0)
		i++;
	all->actual[i] 
}*/

void	print_gridd(int grid[100])
{
	int i = 0;

	while (grid[i])
		ft_printf("%d ", grid[i++]);
	ft_printf(".\n");
}

int		ft_backtrack(t_all *all, int iter, int grid[100])
{
	int	rule;

	rule = -1;
	//printf("iter : %d\n", iter);
	//print_gridd(grid);
	if (check_sort(all, grid))
	{
		if (check_len(all->better, grid))
		{
			while (++rule < 100)
				all->better[rule] = grid[rule];
		}
		return (0);
	}
	else
	{
		while (++rule <= 11 && iter < all->iteration_max)
		{
			grid[iter] = rule;
			if (ft_backtrack(all, iter + 1, grid))
				return (1);
		}
		grid[iter] = 0;
		return (0);
	}
}

/*int	ft_backtrack(t_all *all, int iter, int grid[2][all->size], int fct)
{
	//faire les rules silent
	int	rule;

	//rule = 1;
	if (fct)
		add_grid(all, fct);
	//ft_fct_silent(all, fct, &grid);
	if (check_sort(all, grid)) // si la stack A est trié
	{
		if (check_len(all->better, all->actual))
			all->better = all->actual;
		return (1);
	}
	else
	{
		while (rule <= 11)//(toutes les rules sont pas utilisées
		{
			//ft_fct_silent(all, rule, &grid)
			if (iter < all->iteration_max)
				if (ft_backtrack(all, iter + 1, grid, rule))
					return (1);
		}
		return (0);
	}
	
}
*/
void	sort_two(t_all *all)
{
	if (all->a->index > all->a->next->index)
		ft_sa(all);
}

void	sort_three(t_all *all)
{
	t_nbr *tmp;

	tmp = all->a;
	if (tmp->index > tmp->next->index && tmp->next->next->index > tmp->index)//tmp->index == 1 && tmp->next->index == 0)
		ft_sa(all);
	else if (tmp->index > tmp->next->index && tmp->next->index > tmp->next->next->index)
	{
		ft_sa(all);
		ft_rra(all);
	}
	else if (tmp->index > tmp->next->next->index && tmp->next->next->index > tmp->next->index)
		ft_ra(all);
	else if (tmp->index < tmp->next->next->index && tmp->next->next->index < tmp->next->index)
	{
		ft_sa(all);
		ft_ra(all);
	}
	else if (tmp->next->next->index < tmp->index &&  tmp->index < tmp->next->index)
		ft_rra(all);
}

void	sort_four(t_all *all)
{
	(void)all;
	/*
	t_nbr	*tmp;

	tmp = all->a;
	if (tmp->index == 0)
		ft_pb(all);
	else if (tmp->next->index == 0)
	{
		
	}
	sort_three(all);
	*/
}

void	sort_five(t_all *all)
{
	(void)all;
}