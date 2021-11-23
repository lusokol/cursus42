/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:52 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/25 16:49:45 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbr	*ft_lstnew2(int nbr, int index)
{
	t_nbr	*new;

	new = malloc(sizeof(t_nbr));
	if (!(new))
		return (NULL);
	new->nbr = nbr;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back2(t_nbr **alst, t_nbr *new)
{
	t_nbr	*tmp;

	if (!new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = 0;
	}
	else
		*alst = new;
}

void	ft_lst_free(t_nbr *lst)
{
	t_nbr	*tmp;

	tmp = lst;
	while (lst && lst->next)
	{
		lst = lst->next;
		free(tmp);
		tmp = lst;
	}
	if (tmp)
		free(tmp);
}

void	ft_swap_lst(t_nbr *lst1, t_nbr *lst2)
{
	int	tmp;

	tmp = lst1->nbr;
	lst1->nbr = lst2->nbr;
	lst2->nbr = tmp;
	tmp = lst1->index;
	lst1->index = lst2->index;
	lst2->index = tmp;
}

void	ft_take_index(t_all *all)
{
	t_nbr	*tmp;
	t_nbr	*tmp2;

	tmp = all->a;
	while (tmp)
	{
		tmp2 = all->copy;
		while (tmp2 && tmp2->nbr != tmp->nbr)
			tmp2 = tmp2->next;
		if (tmp2 && tmp2->nbr == tmp->nbr)
			tmp->index = tmp2->index;
		tmp = tmp->next;
	}
}

void	ft_lst_sort(t_nbr *lst)
{
	t_nbr	*tmp;
	int		i;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
		{
			i = 0;
			ft_swap_lst(tmp, tmp->next);
			tmp = lst;
		}
		else
		{
			tmp->index = i;
			i++;
			tmp = tmp->next;
			tmp->index = i;
		}
	}
}