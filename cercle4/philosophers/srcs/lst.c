/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:30:52 by macbookpro        #+#    #+#             */
/*   Updated: 2022/01/11 18:16:53 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*ft_lstnew(int i, int j)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!(new))
		return (NULL);
	new->to_do = 1;
	new->index = i;
	new->type = j;
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
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = 0;
	}
	else
		*alst = new;
}
