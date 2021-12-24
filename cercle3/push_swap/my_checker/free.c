/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:36:47 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/24 18:27:37 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_free_all(t_all *lst, int i)
{
	if (i == 1)
		ft_printf("Error\n");
	ft_lst_free(lst->original->a);
	ft_lst_free(lst->original->b);
	free(lst->original);
	if (lst->ac == 2)
		ft_tab_free(lst->tab);
	if (lst->act)
		ft_tab_free(lst->act);
	free(lst);
	exit(0);
}

/*
** lst = NULL;
** system("leaks push_swap");
*/