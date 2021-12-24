/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_silent2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:54:22 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 17:55:01 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	lst = *b;
	if (!(*b) || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
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
