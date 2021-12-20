/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   logic_sort.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: macbookpro <macbookpro@student.42.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/07 11:33:47 by lusokol		   #+#	#+#			 */
/*   Updated: 2021/12/16 10:50:49 by macbookpro	   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

/* ICI pour opti ce que j'envoie dans b au debut */

void	push_b(t_sort *tmp)
{
	while (tmp->a)
		ft_fct(tmp, 5, 1);
}

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

void	calc_merge(t_sort *tmp)
{
	t_nbr	*b;

	b = tmp->b;
	while (b)
	{
		find_higher(b->index, tmp->a, b);
		b = b->next;
	}
}

/* faire un algo de backtracking
** qui genere pour chaque chiffre parmis les size/2 premiers de la liste.
** des rayons qui partent respectivement sur les 5 premiers chiffres
** suivant celui de depart
** et ce jusqu'a la fin
*/

// Gerer les doublons et la redirection vers la bonne 
// fonction (backtracking ou logic sort)

void	check_move(t_sort *tmp, t_all *all)
{
	(void)all;
	calc_up_a(tmp);
	calc_up_b(tmp);
	calc_merge(tmp);
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

void	logic_sort(t_all *all)
{
	t_sort	*tmp;

	tmp = all->qs;
	push_b(all->qs);
	while (tmp->b)
	{
		check_move(tmp, all);
		best_move(tmp);
	}
	last_rotation(tmp);
}
