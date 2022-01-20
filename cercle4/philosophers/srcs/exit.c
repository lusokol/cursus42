/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:07:37 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/19 12:50:52 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	check_stop(t_table *table)
{
	int	i;

	i = 0;
	table->nb_eat_actual++;
	if (table->nb_philo == table->nb_eat_actual)
		table->stop = 1;
}

void	ft_free(t_philo	*philo)
{
	t_table	*table;
	t_philo	*tmp;
	int		i;

	table = philo->table;
	i = table->nb_philo * 2;
	while (i)
	{
		tmp = philo;
		philo = philo->next;
		if (tmp->type == 2)
			pthread_mutex_destroy(&tmp->frk);
		free(tmp);
		i--;
	}
	pthread_mutex_destroy(&table->txt);
	free(table);
}
