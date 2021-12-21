/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 10:03:24 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/21 18:23:46 by lusokol          ###   ########.fr       */
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

void	increment_in(int i, t_backtrack *bt)
{
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

int	fill_iter(t_backtrack *bt, int iter)
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
				bt->tab[i] = new_bt(bt->actual, i);
				if (!(bt->tab[i]))
					return (0);
				increment_in(i, bt);
			}
			else
				bt->tab[i] = NULL;
		}
	}
	return (1);
}

int	ft_backtrack(t_all *all, int iter)
{
	check_iter(all, iter, all->first);
	if (all->result != NULL)
		return (1);
	else
	{
		if (fill_iter(all->first, iter) == 0)
			ft_free_all(all);
		if (ft_backtrack(all, iter + 1))
			return (1);
		return (0);
	}
}
