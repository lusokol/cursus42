/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:06:55 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/21 17:55:14 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_nbr **a, t_nbr **b, int print)
{
	(void)b;
	if (*a && (*a)->next)
		ft_swap_lst(*a, (*a)->next);
	if (print)
		ft_printf("sa\n");
}

void	ft_sb(t_nbr **a, t_nbr **b, int print)
{
	(void)a;
	if (*b && (*b)->next)
		ft_swap_lst(*b, (*b)->next);
	if (print)
		ft_printf("sb\n");
}

void	ft_ss(t_nbr **a, t_nbr **b, int print)
{
	ft_sa(a, b, 0);
	ft_sb(a, b, 0);
	if (print)
		ft_printf("ss\n");
}

void	ft_pa(t_nbr **a, t_nbr **b, int print)
{
	t_nbr	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (print)
		ft_printf("pa\n");
}

void	ft_pb(t_nbr **a, t_nbr **b, int print)
{
	t_nbr	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (print)
		ft_printf("pb\n");
}
