/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:39:34 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/22 17:44:06 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rec(t_plsc *plsc)
{
	int	i;
	int	j;

	i = plsc->m;
	j = 1;
	plsc->s = malloc(sizeof(int) * plsc->lm);
	fill_tab(plsc->s, plsc->lm, 0);
	while (i != -1)
	{
		plsc->s[plsc->lm - j] = i;
		i = plsc->tab[i];
		j++;
	}
}

void	plssc(int *tab, t_plsc *plsc)
{
	int	*l;
	int	max;
	int	i;
	int	j;

	init_tabs(&l, plsc);
	i = -1;
	while (++i <= plsc->max - 1)
	{
		max = 0;
		j = -1;
		while (++j <= i - 1)
		{
			if (tab[j] <= tab[i] && l[j] > max)
			{
				max = l[j];
				plsc->tab[i] = j;
			}
		}
		l[i] = max + 1;
		if (l[i] > l[plsc->m])
			plsc->m = i;
	}
	plsc->lm = l[plsc->m];
	free(l);
}

void	free_plssc(t_plsc *plsc, int *tab)
{
	free(tab);
	free(plsc->tab);
	free(plsc->s);
	free(plsc);
}

void	push_b(t_sort *tmp)
{
	t_plsc	*plsc;
	int		*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	plsc = malloc(sizeof(t_plsc));
	tab = lst_to_tab(tmp->a, plsc);
	plssc(tab, plsc);
	rec(plsc);
	while (i < plsc->max)
	{
		if (plsc->s[j] == i)
		{
			ft_fct(tmp, 6, 1);
			j++;
		}
		else
			ft_fct(tmp, 5, 1);
		i++;
	}
	free_plssc(plsc, tab);
}
