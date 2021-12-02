/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:21 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/02 17:39:55 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_take_pivot(int i, int j, t_all *all)
{
    t_nbr   *tmp;
    
    //ft_printf("partition de %d a %d\n", i, j);
    tmp = all->qs->a;
    while (tmp && tmp->index != j - ((j - i) / 2))
        tmp = tmp->next;
    //ft_printf("find index : %d instead of %d\n", tmp->index, j - ((j - i) / 2));
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

int    sort_b(int i, t_all *all, int pivot)
{
    t_sort *tmp;
    int p_count;

    p_count = 0;
    tmp = all->qs;
    while (i >= 0)
    {
        if (tmp->b->nbr > pivot)
            ft_fct(all->qs, 4, 1);
        else if (tmp->b->nbr < pivot)
            ft_fct(all->qs, 7, 1);
        else if (tmp->b->nbr == pivot)
        {
            //ft_printf("ici\n");
            ft_fct(all->qs, 4, 1);
            //ft_print_lst(all);    
            //ft_printf("iciiiiiiiiiiiiiiiiiiii\n");
            ft_fct(all->qs, 6, 1);
           // ft_printf("fin ici\n");
            p_count++;
        }
       // ft_printf("innnn\n");
        //ft_print_lst(all);
        i--;
    }
    while (p_count--)
        ft_fct(all->qs, 9, 1);
    while (all->qs->b)
    {
        ft_fct(all->qs, 4, 1);
        p_count++;
    }
    return (p_count);
}

int     push_partition(int i, int j, t_all *all, int pivot)
{
    int k;
    int count;

    count = 0;
    k = j - i;
    while (i)
    {
        count++;
        ft_fct(all->qs, 6, 1);
        i--;
        j--;
    }
    while (j >= 0)
    {
        ft_fct(all->qs, 5, 1);
        j--;
    }
    //ft_printf("======================\n");
    //ft_print_lst(all);
    //ft_printf("======================\n");
    j = sort_b(k, all, pivot) + count;
    i = k;
    //ft_printf("k = %d\n", j);
     while (count--)
       ft_fct(all->qs, 9, 1);
    return (j);
}

int    partition(int l, int h, t_all *all)
{
    int pivot;
    int i;
    int j;

    pivot = ft_take_pivot(l, h, all);
    i = l;
    j = h;
    //ft_printf("===========================================\n");
    //ft_printf("Pivot : %d\npartition du %d au %d nbr\nAvant :\n", pivot, l, h);
    //ft_print_lst(all);
    int p = push_partition(i, j, all, pivot);
    //ft_printf("APRES\n");
    //ft_print_lst(all);
    //ft_printf("===========================================\n");
    return (p);
    // while (i < j)
    // {
    //     if (take_nbr_at_index(i, all) < pivot)
    //     {
    //         ft_fct(all->qs, 5, 1);
    //     }
        
    // }
    
    /*pivot = ft_take_pivot(l, h, all);
    i = l;
    j = h;
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
    return (j);*/
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