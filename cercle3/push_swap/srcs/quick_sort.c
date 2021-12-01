/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:21 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/01 16:23:45 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_take_pivot(int i, int j, t_all *all)
{
    t_nbr   *tmp;
    
    tmp = all->qs->a;
    while (tmp && tmp->index != (j - i) / 2)
        tmp = tmp->next;
    return (tmp->nbr);
}

int take_nbr_at_index(int i, t_all *all)
{
    t_nbr   *tmp;
    
    tmp = all->qs->a;
    while (tmp && i > 0)
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
  //  ft_printf("TO SWAP %d et %d, tmp : %d\n", i, j, tmp);
    iter = 0;
    tmp2 = 0;
    tmp_a = lst->a;
    while (tmp2++ < tmp)
        ft_fct(lst, 6, 1);
    //ft_printf("nbr : %d\n", );
    ft_fct(lst, 5, 1);
    tmp2 = 0;
    iter = check_len(j, lst);
    while (tmp2++ < iter)
        ft_fct(lst, 6, 1);
    ft_fct(lst, 5, 1);
    ft_fct(lst, 2, 1);
    ft_fct(lst, 4, 1);
    tmp2 = 0;
    while (tmp2++ < iter)
        ft_fct(lst, 9, 1);
    ft_fct(lst, 4, 1);
    tmp2 = 0;
    while (tmp2++ < tmp)
        ft_fct(lst, 9, 1);
}

int    partition(int l, int h, t_all *all)
{
    int pivot;
    int i;
    int j;

    // pivot = ft_take_pivot(l, h, all);
    // i = l;
    // j = h;
    // //////////////////////
    // while (i < j)
    // {
    //     if (take_nbr_at_index(i, all) < pivot)
    //     {
    //         ft_fct(all->qs, 5, 1);
    //     }
        
    // }
    
    pivot = ft_take_pivot(all);

    while (i < j)
    {
        while (take_nbr_at_index(i, all) <= pivot)// && i < j);
            i++;
        do
        {
            j--;
        } while (take_nbr_at_index(j, all) > pivot);// && j > i);
        if (i < j)
        {
            ft_printf("IN\n");
            ft_printf("swap %d et %d\n", take_nbr_at_index(i, all), take_nbr_at_index(j, all));
            ft_swap_qs(take_nbr_at_index(i, all), take_nbr_at_index(j, all), all->qs);
            ft_printf("\n");
            ft_print_lst(all);
        }
    }
    
     if (l != j)
    {
         ft_printf("OUT\n");
        //ft_print_lst(all);
        ft_printf("swap %d et %d\n", take_nbr_at_index(l, all), take_nbr_at_index(j, all));
        ft_swap_qs(take_nbr_at_index(l, all), take_nbr_at_index(j, all), all->qs);
        ft_printf("\n");
        ft_print_lst(all);
     }
    //ft_printf("APRES.\n");
    //ft_print_lst(all);
    //t_swap_qs(take_nbr_at_index(l, all), take_nbr_at_index(j, all), all->qs);
    return (j);
}

void    ft_quick_sort(int l, int h, t_all *all)
{
    int j;

    //ft_printf("test\n");
    if (l < h)
    {
        //ft_printf("avant\n");
        j = partition(l, h, all);
        //ft_printf("apres\n");
        ft_quick_sort(l, j, all);
        ft_quick_sort(j + 1, h, all);
    }
}