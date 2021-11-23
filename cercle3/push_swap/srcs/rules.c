/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:06:55 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/25 17:50:30 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_all *all)
{
	if (all && all->a && all->a->next)
		ft_swap_lst(all->a, all->a->next);
	if (all->print)
		ft_printf("sa\n");
}

void	ft_sb(t_all *all)
{
	if (all && all->b && all->b->next)
		ft_swap_lst(all->b, all->b->next);
	if (all->print)
		ft_printf("sb\n");
}

void	ft_ss(t_all *all)
{
	all->print = 0;
	ft_sa(all);
	ft_sb(all);
	all->print = 1;
	ft_printf("ss\n");
}

void	ft_pa(t_all *all)
{
	t_nbr	*tmp;

	if (!all->b)
		return ;
	tmp = all->b;
	all->b = all->b->next;
	tmp->next = all->a;
	all->a = tmp;
	if (all->print)
		ft_printf("pa\n");
}

void	ft_pb(t_all *all)
{
	t_nbr	*tmp;

	if (!all->a)
		return ;
	tmp = all->a;
	all->a = all->a->next;
	tmp->next = all->b;
	all->b = tmp;
	if (all->print)
		ft_printf("pb\n");
}

void	ft_ra(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	lst = all->a;
	if (!all->a || !all->a->next)
		return ;
	tmp = all->a;
	all->a = all->a->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
	if (all->print)
		ft_printf("ra\n");
}

void	ft_rb(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	lst = all->b;
	if (!all->b || !all->b->next)
		return ;
	tmp = all->b;
	all->b = all->b->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
	if (all->print)
		ft_printf("rb\n");
}

void	ft_rr(t_all *all)
{
	all->print = 0;
	ft_ra(all);
	ft_rb(all);
	all->print = 1;
	ft_printf("rr\n");
}

void	ft_rra(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	lst = all->a;
	if (!all->a || !all->a->next)
		return ;
	while (lst->next && lst->next->next)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = all->a;
	all->a = tmp;
	if (all->print)
		ft_printf("rra\n");
}

void	ft_rrb(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*lst;

	lst = all->b;
	if (!all->b || !all->b->next)
		return ;
	while (lst->next && lst->next->next)
		lst = lst->next;
	tmp = lst->next;
	lst->next = NULL;
	tmp->next = all->b;
	all->b = tmp;
	if (all->print)
		ft_printf("rrb\n");
}

void	ft_rrr(t_all *all)
{
	all->print = 0;
	ft_rra(all);
	ft_rrb(all);
	all->print = 1;
	ft_printf("rrr\n");
}