/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:18:27 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/11 18:28:53 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	*test_fct(void *arg)
{
	t_philo	*tmp = (t_philo*)arg;
	printf("i am the philosopher number %d\n", tmp->index);
	return (NULL);
}

void	create_lst(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->nb_philo)
	{
		ft_lstadd_back(&(table->lst), ft_lstnew(i + 1, 1));
		ft_lstadd_back(&(table->lst), ft_lstnew(0, 2));
		i++;
	}
}

t_table	*init(char **av, int ac)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->lst = NULL;
	table->nb_philo = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_eat = ft_atoi(av[5]);
	else
		table->nb_eat = 1;
	return (table);
}
// mutex : https://www.thegeekstuff.com/2012/05/c-mutex-examples/
int main(int ac, char **av)
{
	(void)av;
	int			i = 0;
	pthread_t	test;
	t_philo		*tmp;

	if (ac != 5 && ac != 6)
		return (ft_exit("Wrong number of argument.\nIt must be : number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"));
	t_table	*table;
	table = init(av, ac);
	create_lst(table);		
	tmp = table->lst;
	while (++i <= table->nb_philo)
	{
		//printf("sending the philosopher number %d\n", tmp->index);
		pthread_create(&test, NULL, &test_fct, (void*)tmp);
		tmp = tmp->next->next;
	}
	sleep(1);
}