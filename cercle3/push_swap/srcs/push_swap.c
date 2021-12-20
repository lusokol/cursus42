/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:57 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/16 10:47:45 by macbookpro       ###   ########.fr       */
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

void	ft_print_iter(t_backtrack *first, int iter)
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

void	ft_bt_free(t_backtrack *lst)
{
	int	i;

	i = 1;
	while (i <= 11)
	{
		if (lst->tab && lst->tab[i])
		{
			ft_bt_free(lst->tab[i]);
			free(lst->tab[i]);
		}
		i++;
	}
	if (lst->tab)
		free(lst->tab);
	if (lst->actual)
		free(lst->actual);
}

int	check_two(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		while (ft_isdigit(av[1][i]))
			i++;
		while (av[1][i] == ' ')
			i++;
		if (av[1][i] && !ft_isdigit(av[1][i]))
		{
			ft_printf("\"%c\" isn't an INT.\nIt must be some INT \
split with spaces.\n", av[1][i]);
			return (0);
		}
	}
	return (1);
}

int	check_two_plus(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]))
			{
				ft_printf("\"%s\" isn't an INT.\nIt must be some INT \
split with spaces.\n", av[j]);
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
		if (!check_two(av))
			return (0);
	if (ac > 2)
		if (!check_two_plus(av))
			return (0);
	return (1);
}

t_all	*lst_init(int ac, char **av)
{
	t_all	*lst;
	int		i;

	i = 0;
	lst = malloc(sizeof(t_all));
	if (!lst)
		exit(0);
	lst->original = NULL;
	lst->qs = NULL;
	lst->copy = NULL;
	lst->print = 1;
	lst->iteration_max = 5;
	lst->result = NULL;
	lst->first = new_bt(NULL, 0);
	if (ac > 2)
	{
		lst->size = ac - 1;
		lst->tab = ++av;
	}
	else
	{
		lst->tab = ft_split(av[1], ' ');
		while (lst->tab && lst->tab[i])
			i++;
		lst->size = i;
	}
	lst->first->in_a = lst->size;
	return (lst);
}

void	print_result(t_all *all, int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_fct(all->original, tab[i++], 1);
}

int	check_nb_arg(t_all *all)
{
	int		i;
	t_nbr	*tmp;

	i = 0;
	tmp = all->original->a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	create_lst(t_all *all)
{
	int	i;

	i = 0;
	all->qs = malloc(sizeof(t_sort));
	all->original = malloc(sizeof(t_sort));
	all->original->a = NULL;
	all->original->b = NULL;
	all->qs->a = NULL;
	all->qs->b = NULL;
	while (i < all->size)
	{
		ft_lstadd_back2(&(all->original->a),
			ft_lstnew2(ft_atoi(all->tab[i]), -1));
		ft_lstadd_back2(&(all->qs->a), ft_lstnew2(ft_atoi(all->tab[i]), -1));
		ft_lstadd_back2(&(all->copy), ft_lstnew2(ft_atoi(all->tab[i]), i));
		i++;
	}
}

int	check_double(t_nbr *lst)
{
	t_nbr	*tmp1;
	t_nbr	*tmp2;

	tmp1 = lst;
	while (tmp1 && tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
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
	ft_bt_free(lst->first);
	ft_lst_free(lst->original->a);
	ft_lst_free(lst->original->b);
	free(lst->original);
	free(lst->qs);
	ft_lst_free(lst->copy);
	return (0);
}
/////// LEAKS A CHECKER