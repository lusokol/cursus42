/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:52 by macbookpro        #+#    #+#             */
/*   Updated: 2022/01/19 13:29:39 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*ft_lstnew(int i, int j, t_table *table)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!(new))
		return (NULL);
	new->to_do = 1;
	new->is_waiting = 0;
	new->index = i;
	new->type = j;
	new->nb_eat = 0;
	new->is_alive = 1;
	new->is_eating = 0;
	new->table = table;
	if (j == 2)
		pthread_mutex_init(&new->frk, NULL);
	new->next = NULL;
	new->prec = NULL;
	return (new);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*tmp;

	if (!new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		tmp = tmp->prec;
		tmp->next = new;
		new->prec = tmp;
	}
	else
		*alst = new;
	new->next = (*alst);
	(*alst)->prec = new;
}
