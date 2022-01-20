/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:04:28 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/19 13:48:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*init(char **av, int ac)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->lst = NULL;
	table->stop = 0;
	table->start_eat = 0;
	table->nb_eat_actual = 0;
	pthread_mutex_init(&table->txt, NULL);
	table->nb_philo = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_eat = ft_atoi(av[5]);
	else
		table->nb_eat = -1;
	return (table);
}

int	check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	create_thread(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = table->lst;
	while (++i <= table->nb_philo)
	{
		pthread_create(&philo->thrd, NULL, &routine_fct, (void *)philo);
		philo = philo->next->next;
	}
	if (table->nb_philo == 0)
	{
		free(table);
		exit (ft_exit("Need at least one philosopher."));
	}
	pthread_create(&table->alive, NULL, &is_alive, (void *)philo);
	gettimeofday(&(table->time_start), NULL);
	table->start_eat = 1;
}

void	create_lst(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		ft_lstadd_back(&(table->lst), ft_lstnew(i + 1, 1, table));
		ft_lstadd_back(&(table->lst), ft_lstnew(0, 2, table));
		i++;
	}
}
