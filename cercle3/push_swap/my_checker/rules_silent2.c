/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_silent2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:57:08 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 17:57:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
