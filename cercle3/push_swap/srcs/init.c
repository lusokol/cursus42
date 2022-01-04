/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:17:04 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/04 14:22:01 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_ac_tab(t_all *lst, char **av)
{
	int	i;

	i = 0;
	lst->tab = ft_split(av[1], ' ');
	while (lst->tab && lst->tab[i])
		i++;
	lst->size = i;
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
	lst->ac = ac;
	lst->iteration_max = 5;
	lst->result = NULL;
	lst->first = new_bt(NULL, 0);
	if (ac > 2)
	{
		lst->size = ac - 1;
		lst->tab = ++av;
	}
	else
		convert_ac_tab(lst, av);
	lst->first->in_a = lst->size;
	return (lst);
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
