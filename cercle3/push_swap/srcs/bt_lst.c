/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:23:28 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 18:23:50 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr	*cp_lst(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	tmp = all->original->a;
	lst = NULL;
	while (tmp)
	{
		ft_lstadd_back2(&lst, ft_lstnew2(tmp->nbr, tmp->index));
		tmp = tmp->next;
	}
	return (lst);
}

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
		return (0);
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
	int			i;

	new = malloc(sizeof(t_backtrack));
	new->actual = cp_actual(actual, nbr);
	if (new->actual == 0)
		return (NULL);
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
