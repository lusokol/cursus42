/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:36:47 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/21 18:05:44 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_sort(t_nbr *a, t_nbr *b)
{
	if (a)
		ft_lst_free(a);
	if (b)
		ft_lst_free(b);
	return (0);
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

void	ft_tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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

void	ft_free_all(t_all *lst)
{
	ft_bt_free(lst->first);
	free(lst->first);
	ft_lst_free(lst->original->a);
	ft_lst_free(lst->original->b);
	ft_lst_free(lst->qs->a);
	ft_lst_free(lst->qs->b);
	free(lst->original);
	free(lst->qs);
	ft_lst_free(lst->copy);
	if (lst->ac == 2)
		ft_tab_free(lst->tab);
	free(lst);
	exit(0);
}
