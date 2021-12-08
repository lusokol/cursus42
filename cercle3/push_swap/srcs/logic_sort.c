/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:33:47 by lusokol           #+#    #+#             */
/*   Updated: 2021/12/08 20:23:37 by lusokol          ###   ########.fr       */
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
        tmp->move_a = i;
        if (increment == 1)
            tmp->sens = 6;
        else
            tmp->sens = 9;
        if (i == (max / 2) + (max % 2))
        {
            if (max % 2 )
                i -= increment;
            increment = -1;
        }
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
        tmp->move_b = i;
        if (increment == 1)
            tmp->sens = 7;
        else
            tmp->sens = 10;
        if (i == (max / 2) + (max % 2))
        {
            if (max % 2 )
            i -= increment;
            increment = -1;
        }
        i += increment;
        tmp = tmp->next;
    }
}

void    find_higher(int i, t_nbr *a, t_nbr *b)
{
    t_nbr   *tmp;
    int     index;

    index = -1;
    tmp = NULL;
    if (a == NULL)
    {
       // ft_printf("ICIIIIIIIIIIII\n");
        b->move = 1 + b->move_b;
        b->move_a = 0;
        b->sens_a = 0;
        return ;
    }
    while (a)
    {
        if (a->index > i && (a->index < index || index == -1))
        {
           tmp = a;
           index = tmp->index;
        }
        a = a->next;
    }
    

// POUR UN CHIFFRE N'AYANT PAS
// D'INDEX PLUS GRAND DANS 'A'
// LE PUSH APRES L'INDEX LE PLUS PETIT




    
    //ft_printf("LAAAAAAAAAAAAA\n");
    b->move = tmp->move_a + 1 + b->move_b;
    b->move_a = tmp->move_a;
    b->sens_a = tmp->sens;
    //if (tmp)
      //  ft_printf("B : %2d, A : %2d, tmp->move_a : %2d, tmp->move_b : %2d, tmp->move : %2d, tmp index : %2d\n", b->nbr, tmp->nbr, tmp->move_a, tmp->move_b, tmp->move, tmp->index);
}

void    calc_merge(t_sort *tmp)
{
    t_nbr   *b;
    
    b = tmp->b;
    while (b)
    {
        find_higher(b->index, tmp->a, b);
        b = b->next;
    }
}

// faire un algo de backtracking
// qui genere pour chaque chiffre parmis les size/2 premiers de la liste.
// des rayons qui partent respectivement sur les 5 premiers chiffres suivant celui de depart
// et ce jusqu'a la fin

void    check_move(t_sort *tmp, t_all *all)
{
    // int i = 0;
    // t_nbr *temp = tmp->b;
    // while (temp)
    //     temp->
    (void)all;
    //ft_printf("\n\n\nAVANT\n");
    calc_up_a(tmp);
    calc_up_b(tmp);
    //ft_printf("\nCHECK ICI\n");
    //ft_print_lst(all);
    //ft_printf("\n000000000000000000000000000000000000000000000000000000\n\n");
    calc_merge(tmp);
    //ft_printf("APRES\n\n");
    //ft_print_lst(all);
    //ft_printf("\nAPRES \n\n\n");
    // ft_printf("\n545645645645646456456465456456456456456456544545645456456456465456\n\n\n");
}

void    do_move(t_nbr *low, t_sort *tmp)
{
    while (low->sens_a == 6 && low->sens == 7 && low->move_a && low->move_b)
    {
        low->move_a--;
        low->move_b--;
        ft_fct(tmp, 8, 1);
    }
    while (low->sens_a == 9 && low->sens == 10 && low->move_a && low->move_b)
    {
        low->move_a--;
        low->move_b--;
        ft_fct(tmp, 11, 1);
    }
    while (low->move_a--)
        ft_fct(tmp, low->sens_a, 1);
    while (low->move_b--)
        ft_fct(tmp, low->sens, 1);

    /////////faire dans les deux sens rrr ou rr
    ft_fct(tmp, 4, 1);
}

void    best_move(t_sort *tmp)
{
    t_nbr   *b;
    t_nbr   *lowest;

    b = tmp->b;
    lowest = b;
    while (b)
    {
        if (lowest->move > b->move)
            lowest = b;
        b = b->next;
    }
    //ft_print_lst(all);
    //ft_printf("lowest : %d, index : %d\n", lowest->nbr, lowest->index);
    //ft_printf("rotate a : %d, rotate b : %d\n", lowest->move_a, lowest->move_b);
    do_move(lowest, tmp);//lowest->move, lowest->sens, lowest->move_a, lowest->sens_a);
    //ft_print_lst(all);
}

void    last_rotation(t_sort *tmp)
{
    int     move;
    int     sens;
    t_nbr   *a;

    a = tmp->a;
    move = 0;
    sens = 0;
    calc_up_a(tmp);
    calc_up_b(tmp);
    while (a)
    {
        if (a->index == 0)
        {
            move = a->move_a;
            sens = a->sens_a;
            break ;
        }
        a = a->next;
    }
    while (move--)
        ft_fct(tmp, a->sens_a, 1);
}

void    logic_sort(t_all *all)
{
    t_sort  *tmp;

    tmp = all->qs;
    //ft_print_lst(all);
    push_b(all->qs);
    while (tmp->b)
    {
        //ft_printf("\n\n==========================\n\n");
       // ft_print_lst(all);
        check_move(tmp, all);
      //  ft_printf("\n===================AVANT\n");
      //  ft_print_lst(all);
        best_move(tmp);
       // ft_printf("\n===================APRES\n");
        //ft_print_lst(all);
    }
    last_rotation(tmp);
    //ft_print_lst(all);
}