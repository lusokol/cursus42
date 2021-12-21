/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:48:31 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 17:49:30 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_sort *tmp)
{
	while (tmp->a)
		ft_fct(tmp, 5, 1);
}

void	do_move(t_nbr *low, t_sort *tmp)
{
	while (low->sens_a == 6 && low->sens == 7 && low->move_a && low->move_b)
	{
		low->move_a--;
		low->move_b--;
		ft_fct(tmp, 8, 1);
	}
	while (low->sens_a == 9 && low->sens == 10 && low->move_a && low->move_b)
	{
		low->move_a--;
		low->move_b--;
		ft_fct(tmp, 11, 1);
	}
	while (low->move_a--)
		ft_fct(tmp, low->sens_a, 1);
	while (low->move_b--)
		ft_fct(tmp, low->sens, 1);
	ft_fct(tmp, 4, 1);
}

void	best_move(t_sort *tmp)
{
	t_nbr	*b;
	t_nbr	*lowest;

	b = tmp->b;
	lowest = b;
	while (b)
	{
		if (lowest->move > b->move)
			lowest = b;
		b = b->next;
	}
	do_move(lowest, tmp);
}

void	last_rotation(t_sort *tmp)
{
	int		move;
	int		sens;
	t_nbr	*a;

	a = tmp->a;
	move = 0;
	sens = 0;
	calc_up_a(tmp);
	calc_up_b(tmp);
	while (a)
	{
		if (a->index == 0)
		{
			move = a->move_a;
			sens = a->sens_a;
			break ;
		}
		a = a->next;
	}
	while (move--)
		ft_fct(tmp, a->sens_a, 1);
}
