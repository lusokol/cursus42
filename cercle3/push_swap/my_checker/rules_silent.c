/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_silent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:06:55 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/21 17:57:36 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ssa(t_nbr **a, t_nbr **b)
{
	(void)b;
	if (*a && (*a)->next)
		ft_swap_lst(*a, (*a)->next);
}

void	ft_ssb(t_nbr **a, t_nbr **b)
{
	(void)a;
	if (*b && (*b)->next)
		ft_swap_lst(*b, (*b)->next);
}

void	ft_sss(t_nbr **a, t_nbr **b)
{
	ft_ssa(a, b);
	ft_ssb(a, b);
}

void	ft_spa(t_nbr **a, t_nbr **b)
{
	t_nbr	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	ft_spb(t_nbr **a, t_nbr **b)
{
	t_nbr	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
