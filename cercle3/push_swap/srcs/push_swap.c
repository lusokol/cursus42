/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:57 by macbookpro        #+#    #+#             */
/*   Updated: 2021/11/23 17:11:48 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_all *all)
{
	t_nbr	*tmp;
	int		i;

	i = 0;
	tmp = all->a;
	while (tmp)
	{
		ft_printf("[A] tmp->nbr : %d\ttmp->index : %d\n", tmp->nbr, tmp->index);
		tmp = tmp->next;
	}
	ft_printf("\n");
	tmp = all->b;
	while (tmp)
	{
		i++;
		ft_printf("[B] tmp->nbr : %d\ttmp->index : %d\n", tmp->nbr, tmp->index);
		tmp = tmp->next;
	}
}

void	ft_sort_push(t_all *all)
{
	if (all->size == 2)
		sort_two(all);
	else if (all->size == 3)
		sort_three(all);
	else if (all->size == 4)
		sort_four(all);
	else if (all->size == 5)
		sort_five(all);
}

void	ft_fct(t_all *all, int fct)
{
	if (fct == 1)
		ft_sa(all);
	else if (fct == 2)
		ft_sb(all);
	else if (fct == 3)
		ft_ss(all);
	else if (fct == 4)
		ft_pa(all);
	else if (fct == 5)
		ft_pb(all);
	else if (fct == 6)
		ft_ra(all);
	else if (fct == 7)
		ft_rb(all);
	else if (fct == 8)
		ft_rr(all);
	else if (fct == 9)
		ft_rra(all);
	else if (fct == 10)
		ft_rrb(all);
	else if (fct == 11)
		ft_rrr(all);
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

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
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
	}
	if (ac > 2)
	{
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
	}
	return (1);
}

t_all	*lst_init(int ac, char **av)
{
	t_all	*lst;

	lst = malloc(sizeof(t_all));
	if (!lst)
		exit(0);
	lst->a = NULL;
	lst->b = NULL;
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
		int i = 0;
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
		ft_fct(all, tab[i++]);
}

int	main(int ac, char **av)
{
	t_all	*lst;
	int		i;

	if (check_arg(ac, av) == 0)
		return (0);
	i = 0;
	lst = lst_init(ac, av);
	while (i < lst->size)
	{
		ft_lstadd_back2(&(lst->a), ft_lstnew2(ft_atoi(lst->tab[i]), i));
		ft_lstadd_back2(&(lst->copy), ft_lstnew2(ft_atoi(lst->tab[i]), i));
		i++;
	}
	ft_lst_sort(lst->copy);
	ft_take_index(lst);
	ft_backtrack(lst, 0);
	ft_printf("===========================================*\n");
	ft_print_lst(lst);
	ft_printf("===========================================*\n");
	print_result(lst, lst->result);
	ft_printf("===========================================*\n");
	ft_print_lst(lst);
	ft_bt_free(lst->first);
	ft_lst_free(lst->a);
	ft_lst_free(lst->b);
	ft_lst_free(lst->copy);
	//system("leaks push_swap");
	return (0);
}
/////// LEAKS A CHECKER