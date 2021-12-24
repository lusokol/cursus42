/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:54:24 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/24 18:26:03 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra(t_nbr **a, t_nbr **b, int print)
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
	if (print)
		ft_printf("rra\n");
}

void	ft_rrb(t_nbr **a, t_nbr **b, int print)
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
