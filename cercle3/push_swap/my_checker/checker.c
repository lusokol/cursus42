/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:57 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/24 18:28:27 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_do_act(char *tab, t_all *lst)
{
	if (!ft_strncmp(tab, "sa", 4))
		ft_fct(lst->original, 1, 0);
	else if (!ft_strncmp(tab, "sb", 4))
		ft_fct(lst->original, 2, 0);
	else if (!ft_strncmp(tab, "ss", 4))
		ft_fct(lst->original, 3, 0);
	else if (!ft_strncmp(tab, "pa", 4))
		ft_fct(lst->original, 4, 0);
	else if (!ft_strncmp(tab, "pb", 4))
		ft_fct(lst->original, 5, 0);
	else if (!ft_strncmp(tab, "ra", 4))
		ft_fct(lst->original, 6, 0);
	else if (!ft_strncmp(tab, "rb", 4))
		ft_fct(lst->original, 7, 0);
	else if (!ft_strncmp(tab, "rr", 4))
		ft_fct(lst->original, 8, 0);
	else if (!ft_strncmp(tab, "rra", 4))
		ft_fct(lst->original, 9, 0);
	else if (!ft_strncmp(tab, "rrb", 4))
		ft_fct(lst->original, 10, 0);
	else if (!ft_strncmp(tab, "rrr", 4))
		ft_fct(lst->original, 11, 0);
	else
		return (0);
	return (1);
}

int	check_sort(t_sort *lst)
{
	t_nbr	*tmp;

	if (lst->b)
		return (0);
	tmp = lst->a;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_all	*lst;
	int		i;

	if (check_arg(ac, av) == 0)
		return (0);
	lst = lst_init(ac, av);
	create_lst(lst);
	if (check_double(lst->original->a))
		ft_free_all(lst, 1);
	read_arg(lst);
	i = 0;
	while (lst->act && lst->act[i])
	{
		if (ft_do_act(lst->act[i], lst) == 0)
			ft_free_all(lst, 1);
		i++;
	}
	if (check_sort(lst->original))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_all(lst, 0);
	return (0);
}

/*
** lst = NULL;
** system("leaks push_swap");
*/