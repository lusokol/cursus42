/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_silent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:06:55 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/25 17:50:49 by macbookpro       ###   ########.fr       */
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

void	ft_sra(t_nbr **a, t_nbr **b)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)b;
	lst = *a;
	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
}

void	ft_srb(t_nbr **a, t_nbr **b)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)a;
	lst = *b;
	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
}

void	ft_srr(t_nbr **a, t_nbr **b)
{
	ft_sra(a, b);
	ft_srb(a, b);
}

void	ft_srra(t_nbr **a, t_nbr **b)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)b;
	lst = *a;
	if (!(*a) || !(*a)->next)
		return ;
	while (lst->next && lst->next->next)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

void	ft_srrb(t_nbr **a, t_nbr **b)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)a;
	lst = *b;
	if (!(*b) || !(*b)->next)
		return ;
	while (lst->next && lst->next->next)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = *b;
	*b = tmp;
}

void	ft_srrr(t_nbr **a, t_nbr **b)
{
	ft_srra(a, b);
	ft_srrb(a, b);
}