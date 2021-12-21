/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:40:51 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 17:53:14 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_max(t_nbr *temp)
{
	int		max;
	t_nbr	*tmp;

	max = 0;
	tmp = temp;
	while (tmp)
	{
		tmp = tmp->next;
		max++;
	}
	return (max);
}

void	calc_up_a(t_sort *lst)
{
	int		max;
	int		i;
	int		increment;
	t_nbr	*tmp;

	i = 0;
	tmp = lst->a;
	max = count_max(tmp);
	increment = 1;
	while (tmp)
	{
		tmp->move_a = i;
		if (increment == 1)
			tmp->sens_a = 6;
		else
			tmp->sens_a = 9;
		if (i == (max / 2) && increment != -1)
		{
			i += increment * (max % 2);
			increment = -1;
		}
		i += increment;
		tmp = tmp->next;
	}
}

void	calc_up_b(t_sort *lst)
{
	int		max;
	int		i;
	int		increment;
	t_nbr	*tmp;

	i = 0;
	tmp = lst->b;
	max = count_max(tmp);
	increment = 1;
	while (tmp)
	{
		tmp->move_b = i;
		tmp->sens = 10;
		if (increment == 1)
			tmp->sens = 7;
		if (i == (max / 2) && increment != -1)
		{
			i += increment * (max % 2);
			increment = -1;
		}
		i += increment;
		tmp = tmp->next;
	}
}
