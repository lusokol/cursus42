/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:57 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/21 17:38:54 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fct(t_sort *all, int fct, int print)
{
	if (fct == 1)
		ft_sa(&all->a, &all->b, print);
	else if (fct == 2)
		ft_sb(&all->a, &all->b, print);
	else if (fct == 3)
		ft_ss(&all->a, &all->b, print);
	else if (fct == 4)
		ft_pa(&all->a, &all->b, print);
	else if (fct == 5)
		ft_pb(&all->a, &all->b, print);
	else if (fct == 6)
		ft_ra(&all->a, &all->b, print);
	else if (fct == 7)
		ft_rb(&all->a, &all->b, print);
	else if (fct == 8)
		ft_rr(&all->a, &all->b, print);
	else if (fct == 9)
		ft_rra(&all->a, &all->b, print);
	else if (fct == 10)
		ft_rrb(&all->a, &all->b, print);
	else if (fct == 11)
		ft_rrr(&all->a, &all->b, print);
}

/*void	ft_print_iter(t_backtrack *first, int iter)
{
	int	i;
	int	j;

	i = 0;
	if (iter > 0)
	{
		while (++i <= 11)
			if (first->tab[i] != NULL)
				ft_print_iter(first->tab[i], iter - 1);
	}
	else
	{
		while (++i <= 11)
		{
			if (first->tab[i])
			{
				ft_printf("\"");
				j = 0;
				while (first->tab[i] && first->tab[i]->actual[j] != 0)
					ft_printf("%d ", first->tab[i]->actual[j++]);
				ft_printf("\"\n");
			}
		}
	}
}
*/

void	print_result(t_all *all, int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_fct(all->original, tab[i++], 1);
}

int	main(int ac, char **av)
{
	t_all	*lst;
	int		i;

	if (check_arg(ac, av) == 0)
		return (0);
	i = 0;
	lst = lst_init(ac, av);
	create_lst(lst);
	if (check_double(lst->original->a))
	{
		ft_printf("Doublon detected !\n");
		return (0);
	}
	ft_lst_sort(lst->copy);
	ft_take_index(lst);
	if (check_nb_arg(lst) <= 5)
	{
		ft_backtrack(lst, 0);
		print_result(lst, lst->result);
	}
	else
		logic_sort(lst);
	ft_free_all(lst);
	return (0);
}

/*
** lst = NULL;
** system("leaks push_swap");
*/