/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:03:24 by macbookpro        #+#    #+#             */
/*   Updated: 2021/11/23 16:52:51 by lusokol          ###   ########.fr       */
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

int	check_sort(t_all *all, int *grid)
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


/*void	add_grid(t_all *all, int fct)
{
	int	i;

	i = 0;
	while (all->actual[i] != 0)
		i++;
	all->actual[i] 
}*/

int	*cp_actual(int *grid, int last)
{
	int	i;
	int	*tab;

	i = 0;
	while (grid && grid[i])
		i++;
	i++;
	tab = malloc(sizeof(int) * (i + 1));
	if (!tab)
		return (0);//ft_exit(please);
	tab[i] = 0;
	i = 0;
	while (tab && grid && grid[i])
	{
		tab[i] = grid[i];
		i++;
	}
	tab[i] = last;
	return (tab);
}

t_backtrack	*new_bt(int *actual, int nbr)
{
	t_backtrack	*new;
	int	i;

	new = malloc(sizeof(t_backtrack));
	new->actual = cp_actual(actual, nbr);
	i = 0;
	new->tab = malloc(sizeof(t_backtrack) * 12);
	while (i <= 11)
	{
		new->tab[i++] = NULL;
	}
	new->in_a = 0;
	new->in_b = 0;
	return (new);
}

int	check_new(int a, int b, t_backtrack *tmp)
{
	if (a == 0 && (b == 2 || b == 3 || b == 4 || b == 7 || b == 8 || b == 10 || b == 11))
		return (0);
	if (a == 1 && b == 1)
		return (0);
	if (a == 2 && b == 2)
		return (0);
	if (a == 3 && b == 3)
		return (0);
	if ((a == 4 && b == 5) || (a == 5 && b == 4))
		return (0);
	if ((a == 6 && (b == 9 || b == 11)) || (a == 9 && (b == 6 || b == 8)))
		return (0);
	if ((a == 7 && (b == 10 || b == 11)) || (a == 10 && (b == 7 || b == 8)))
		return (0);
	if ((a == 9 && b == 10) || (a == 10 && b == 9))
		return (0);
	if ((a == 6 && b == 7) || (a == 7 && b == 6))
		return (0);
	if ((a == 1 && b == 2) || (a == 2 && b == 1))
		return (0);
	if ((a == 1 || a == 2) && b == 3)
		return (0);
	if ((b == 1 || b == 2) && a == 3)
		return (0);
	if ((a == 8 && b == 11) || (a == 11 && b == 8))
		return (0);
	if (tmp->in_a < 2 && (b == 1 || b == 3 || b == 6 || b == 8 || b == 9 || b == 11))
		return (0);
	if (tmp->in_b < 2 && (b == 2 || b == 3 || b == 7 || b == 8 || b == 10 || b == 11))
		return (0);
	if ((tmp->in_a <= 0 && b == 5) || (tmp->in_b <= 0 && b == 4))
		return (0);
	return (1);
}

int	take_last(int *tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	if (!tab[i])
		return (0);
	while (tab && tab[i] && tab[i + 1])
		i++;
	return (tab[i]);
}

void	fill_iter(t_backtrack *bt, int iter)
{
	int	i;

	i = 0;
	if (iter > 0)
	{
		while (++i <= 11)
			if (bt->tab[i] != NULL)
				fill_iter(bt->tab[i], iter - 1);
				
	}
	else
	{
		while (++i <= 11)
		{
			if (check_new(take_last(bt->actual), i, bt))
			{
				if (!(bt->tab[i] = new_bt(bt->actual, i)))
					return ;
				bt->tab[i]->in_a = bt->in_a;
				bt->tab[i]->in_b = bt->in_b;
				if (i == 4)
				{
					bt->tab[i]->in_a += 1;
					bt->tab[i]->in_b -= 1;
				}
				if (i == 5)
				{
					bt->tab[i]->in_a -= 1;
					bt->tab[i]->in_b += 1;
				}
			}
			else
			{
				bt->tab[i] = NULL;
			}
		}
	}
}

int	*check_iter(t_all *all, int iter, t_backtrack *bt)
{
	int	i;

	i = 0;
	if (iter > 0)
	{
		while (all->result == NULL && ++i <= 11)
			if (bt->tab[i] != NULL)
				check_iter(all, iter - 1, bt->tab[i]);
	}
	else
	{
		if (all->result == NULL && check_sort(all, bt->actual))
			all->result = bt->actual;
	}
	return (0);
}

int		ft_backtrack(t_all *all, int iter)
{
	check_iter(all, iter, all->first);
	if (all->result != NULL/* || iter >= 5*/)
		return (1);
	else
	{
		ft_printf("fill iter %d\n", iter);
		fill_iter(all->first, iter);
		if (ft_backtrack(all, iter + 1))
			return (1);
		return (0);
	}
}

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