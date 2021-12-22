/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:35:11 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/22 17:35:44 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_tab(int *tab, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
		tab[i++] = value;
}

void	init_tabs(int **l, t_plsc *plsc)
{
	*l = malloc(sizeof(int) * plsc->max);
	plsc->tab = malloc(sizeof(int) * plsc->max);
	fill_tab(*l, plsc->max, 1);
	fill_tab(plsc->tab, plsc->max, -1);
	plsc->m = 0;
}

int	*lst_to_tab(t_nbr *a, t_plsc *plsc)
{
	int		max;
	int		*tab;
	t_nbr	*tmp;

	max = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		max++;
	}
	tab = malloc(sizeof(int) * max + 1);
	tab[max] = 0;
	tmp = a;
	plsc->max = max;
	max = 0;
	while (tmp)
	{
		tab[max++] = tmp->nbr;
		tmp = tmp->next;
	}
	return (tab);
}
