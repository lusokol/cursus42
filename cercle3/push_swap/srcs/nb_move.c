/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:47:46 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 17:53:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr	*find_lower(int i, t_nbr *a, t_nbr *high)
{
	t_nbr	*tmp;
	t_nbr	*low;
	int		index;

	if (high != NULL)
		return (high);
	low = a;
	index = i;
	tmp = NULL;
	while (low)
	{
		if (low->index < i && (low->index < index || index == i))
		{
			tmp = low;
			index = tmp->index;
		}
		low = low->next;
	}
	return (tmp);
}

void	ft_assign(t_nbr *b, t_nbr *tmp)
{
	b->move = tmp->move_a + 1 + b->move_b;
	b->move_a = tmp->move_a;
	b->sens_a = tmp->sens_a;
}

void	find_higher(int i, t_nbr *a, t_nbr *b)
{
	t_nbr	*tmp;
	t_nbr	*high;
	int		index;

	high = a;
	index = -1;
	tmp = NULL;
	if (high == NULL)
	{
		b->move = 1 + b->move_b;
		b->move_a = 0;
		b->sens_a = 0;
		return ;
	}
	while (high)
	{
		if (high->index > i && (high->index < index || index == -1))
			tmp = high;
		if (high->index > i && (high->index < index || index == -1))
			index = tmp->index;
		high = high->next;
	}
	tmp = find_lower(i, a, tmp);
	ft_assign(b, tmp);
}
