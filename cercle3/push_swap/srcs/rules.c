/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:06:55 by macbookpro        #+#    #+#             */
/*   Updated: 2021/11/30 17:43:02 by lusokol          ###   ########.fr       */
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

void	ft_ra(t_nbr **a, t_nbr **b, int print)
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
	if (print)
		ft_printf("ra\n");
}

void	ft_rb(t_nbr **a, t_nbr **b, int print)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)a;
	lst = b;
	if (!b || !b->next)
		return ;
	tmp = b;
	b = b->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	ft_rr(t_nbr **a, t_nbr **b, int print)
{
	ft_ra(a, b, 0);
	ft_rb(a, b, 0);
	if (print)
		ft_printf("rr\n");
}

void	ft_rra(t_nbr **a, t_nbr **b, int print)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)b;
	lst = a;
	if (!a || !a->next)
		return ;
	while (lst->next && lst->next->next)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = a;
	a = tmp;
	if (print)
		ft_printf("rra\n");
}

void	ft_rrb(t_nbr **a, t_nbr **b, int print)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	(void)a;
	lst = b;
	if (!b || !b->next)
		return ;
	while (lst->next && lst->next->next)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = b;
	b = tmp;
	if (print)
		ft_printf("rrb\n");
}

void	ft_rrr(t_nbr **a, t_nbr **b, int print)
{
	ft_rra(a, b, 0);
	ft_rrb(a, b, 0);
	if (print)
		ft_printf("rrr\n");
}