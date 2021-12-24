/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_silent3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:57:11 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 17:57:40 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
