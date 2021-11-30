/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:21 by lusokol           #+#    #+#             */
/*   Updated: 2021/11/30 16:24:12 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_quick_sort(int l, int h, t_all *all)
{
    int j;

    if (l < h)
    {
        j = partition(l, h, all);
        ft_quick_sort(l, j, all);
        ft_quick_sort(j + 1, h, all);
    }
}

int ft_take_pivot(int i, t_all *all)
{
    t_nbr   *tmp;
    
    tmp = all->qs->a;
    while (tmp && i)
    {
        tmp = tmp->next;
        i--;
    }
    if (!tmp)
        return (0);
    return (tmp->nbr);
}

int check_len(int i, t_sort *lst)
{
    t_nbr   *tmp;
    int     j;

    j = 0;
    tmp = lst->a;
    while (tmp && tmp->nbr != i)
    {
        j++;
        tmp = tmp->next;
    }
    return (j);
}

void    ft_swap_qs(int i, int j, t_sort *lst)
{
    int     tmp;
    int     tmp2;
    t_nbr   *tmp_a;
    int     iter;
    
    tmp = check_len(i, lst);
    iter = 0;
    tmp2 = 0;
    tmp_a = lst->a;
    while (tmp2++ < tmp)
        ft_fct(lst, 6, 1);
    ft_fct(lst, 5, 1);
    tmp2 = 0;
    iter = check_len(j, lst);
    while (tmp2++ < iter)
        ft_fct(lst, 6, 1);
    ft_fct(lst, 5, 1);
    ft_fct(lst, 2, 1);
    ft_fct(lst, 4, 1);
    tmp2 = 0;
    while (tmp2++ < iter + tmp)
        ft_fct(lst, 9, 1);
}

int    partition(int l, int h, t_all *all)
{
    int pivot;
    int i;
    int j;

    pivot = ft_take_pivot(l, all);
    i = l;
    j = h;
    while (i < j)
    {
        i++;
        while (ft_take_pivot(i, all) <= pivot)
            i++;
        j--;
        while (ft_take_pivot(j, all) > pivot)
            j--;
        if (i < j)
            ft_swap_qs(ft_take_pivot(i, all), ft_take_pivot(j, all), all->qs);
    }
}