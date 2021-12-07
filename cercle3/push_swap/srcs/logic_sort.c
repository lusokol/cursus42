/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:33:47 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/07 19:09:05 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_b(t_sort   *tmp)
{
    while (tmp->a)
        ft_fct(tmp, 5, 1);// ICI pour opti ce que j'envoie dans b au debut
}

void    calc_up_a(t_sort *lst)
{
    int     max;
    int     i;
    int     increment;
    t_nbr   *tmp;

    max = 0;
    i = 0;    
    tmp = lst->a;
    while (tmp)
    {
        tmp = tmp->next;
        max++;
    }
    tmp = lst->a;
    increment = 1;
    while (tmp)
    {
        tmp->move = i;
        if (increment == 1)
            tmp->sens = 1;
        else
            tmp->sens = 2;
        if (i == (max / 2) + (max % 2))
            increment = -1;
        i += increment;
        tmp = tmp->next;
    }
}

void    calc_up_b(t_sort *lst)
{
    int     max;
    int     i;
    int     increment;
    t_nbr   *tmp;

    max = 0;
    i = 0;    
    tmp = lst->b;
    while (tmp)
    {
        tmp = tmp->next;
        max++;
    }
    tmp = lst->b;
    increment = 1;
    while (tmp)
    {
        tmp->move = i;
        if (increment == 1)
            tmp->sens = 1;
        else
            tmp->sens = 2;
        if (i == (max / 2) + (max % 2))
            increment = -1;
        i += increment;
        tmp = tmp->next;
    }
}

void    calc_merge(t_sort *tmp)
{
    t_nbr   *b;
    
    b = tmp->b;
    while ()
}

// faire un algo de backtracking
// qui genere pour chaque chiffre parmis les size/2 premiers de la liste.
// des rayons qui partent respectivement sur les 5 premiers chiffres suivant celui de depart
// et ce jusqu'a la fin

void    check_move(t_sort *tmp)
{
    
    // ft_fct(tmp, 4, 1);
    // ft_fct(tmp, 4, 1);
    // ft_fct(tmp, 4, 1);
    // ft_fct(tmp, 4, 1);
    calc_up_a(tmp);
    calc_up_b(tmp);
    calc_merge(tmp);
}

void    logic_sort(t_all *all)
{
    t_sort  *tmp;

    tmp = all->qs;
    push_b(all->qs);
    check_move(tmp);
    // while (tmp->b)
    // {
    //     check_move(tmp);
        
    // }
    ft_print_lst(all);
}