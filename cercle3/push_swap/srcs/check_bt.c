/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:14:08 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 18:24:10 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (free_sort(a, b));
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (free_sort(a, b));
		tmp = tmp->next;
	}
	return (free_sort(a, b) + 1);
}

int	check_new(int a, int b, t_backtrack *tmp)
{
	if (a == 0 && (b == 2 || b == 3 || b == 4 || b == 7 || b == 8
			|| b == 10 || b == 11))
		return (0);
	if ((a == 1 && b == 1) || (a == 2 && b == 2) || (a == 3 && b == 3))
		return (0);
	if ((a == 4 && b == 5) || (a == 5 && b == 4))
		return (0);
	if ((a == 6 && (b == 9 || b == 11)) || (a == 9 && (b == 6 || b == 8)))
		return (0);
	if ((a == 7 && (b == 10 || b == 11)) || (a == 10 && (b == 7 || b == 8)))
		return (0);
	if (((a == 9 && b == 10) || (a == 10 && b == 9)) || ((a == 6 && b == 7)
			|| (a == 7 && b == 6)) || ((a == 1 && b == 2)
			|| (a == 2 && b == 1)))
		return (0);
	if (((a == 1 || a == 2) && b == 3) || ((b == 1 || b == 2) && a == 3))
		return (0);
	if ((a == 8 && b == 11) || (a == 11 && b == 8))
		return (0);
	if ((tmp->in_a < 2 && (b == 1 || b == 3 || b == 6 || b == 8 || b == 9
				|| b == 11)) || (tmp->in_b < 2 && (b == 2 || b == 3 || b == 7
				|| b == 8 || b == 10 || b == 11)) || ((tmp->in_a <= 0
				&& b == 5) || (tmp->in_b <= 0 && b == 4)))
		return (0);
	return (1);
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
