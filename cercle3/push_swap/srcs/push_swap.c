/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:09:57 by macbookpro        #+#    #+#             */
/*   Updated: 2022/01/04 17:31:17 by lusokol          ###   ########.fr       */
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

void	print_result(t_all *all, int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_fct(all->original, tab[i++], 1);
}

long long int	ft_latoi(char *str)
{
	int				i;
	int				negative;
	long long int	res;

	i = 0;
	negative = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = negative * -1;
		i++;
	}
	while ((ft_isdigit(str[i])) && str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * negative);
}

int	check_ovf(char **tab)
{
	int				i;
	long long int	l;

	i = 0;
	while (tab[i])
	{
		l = ft_latoi(tab[i]);
		if (l > 2147483647 || l < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_all	*lst;

	if (check_arg(ac, av) == 0)
		return (0);
	lst = lst_init(ac, av);
	create_lst(lst);
	if (!check_ovf(lst->tab) || check_double(lst->original->a))
	{
		ft_printf("Error\n");
		ft_free_all(lst);
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