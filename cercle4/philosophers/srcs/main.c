/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:18:27 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/20 16:31:22 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*is_alive(void *arg)
{
	t_philo	*philo;
	int		alive;

	philo = (t_philo *)arg;
	alive = 1;
	while (alive == 1 && philo->table->start_eat == 1)
	{
		usleep(10);
		if (philo->type == 1 && philo->is_waiting == 1)
		{
			if (calc_ms_pass(philo->last_eat) >= philo->table->time_die)
			{
				fork_unlock(philo);
				aff_philo(philo, 5);
				philo->table->stop = 1;
			}
		}
		philo = philo->next;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int			i;
	t_philo		*philo;
	t_table		*table;

	i = 0;
	if (ac != 5 && ac != 6)
		return (ft_exit("Wrong number of argument.\nIt must be : number_of_phi\
losophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"));
	if (check_arg(av))
		return (ft_exit("Wrong arguments. It must be only positive number."));
	table = init(av, ac);
	create_lst(table);
	create_thread(table);
	i = 0;
	philo = table->lst;
	while (++i <= table->nb_philo)
	{
		pthread_join(philo->thrd, NULL);
		philo = philo->next->next;
	}
	ft_free(table->lst);
	return (0);
}

/*
	philo = NULL;
	table = NULL;
	system ("leaks philosophers");
*/