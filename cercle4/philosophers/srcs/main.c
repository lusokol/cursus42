/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:18:27 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/12 18:15:43 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb += 2000000000;
		}
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

char	*txt(int i)
{
	if (i == 1)
		return (" has taken a fork\n");
	if (i == 2)
		return (" is eating\n");
	if (i == 3)
		return (" is sleeping\n");
	if (i == 4)
		return (" is thinking\n");
	if (i == 5)
		return (" died\n");
	return ("");
}

void	aff_philo(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->table->txt);
	ft_putnbr(philo->index);
	char *str = txt(i);
	write (1, str, strlen(str));
	pthread_mutex_unlock(&philo->table->txt);
}

void	fork_lock(t_philo *philo)
{
	pthread_mutex_lock(&(philo->prec->frk));
	aff_philo(philo, 1);
	pthread_mutex_lock(&(philo->next->frk));
	aff_philo(philo, 1);
}

void	fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prec->frk);
	pthread_mutex_unlock(&philo->next->frk);
}

long long int	calc_ms_pass(struct timeval start)
{
	struct timeval	end;
	long long int	diff;
	gettimeofday(&end, NULL);
	diff = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
	//printf("diff : %lld\n", diff);
	diff /= 1000;
	//printf("diff : %lld\n", diff);
	return (diff);
}

void	eat(t_philo *philo)
{
	aff_philo(philo, 2);
	usleep(philo->table->time_eat * 1000);
	if (calc_ms_pass(philo->last_eat) >= philo->table->time_die)
			philo->is_alive = 0;
}

void	sleeping(t_philo *philo)
{
	aff_philo(philo, 3);
	usleep(philo->table->time_sleep * 1000);
	if (calc_ms_pass(philo->last_eat) >= philo->table->time_die)
			philo->is_alive = 0;
	if (philo->is_alive == 1 && philo->table->stop == 0)
		aff_philo(philo, 4);
}

/*
void	eat(t_philo *philo)
{
	struct timeval	start;
	long long int	diff;

	aff_philo(philo, 2);
	gettimeofday(&start, NULL);
	gettimeofday(&philo->last_eat, NULL);
	diff = calc_ms_pass(start);
	while (diff < philo->table->time_eat && philo->table->stop == 0)
	{
		diff = calc_ms_pass(start);
		if (calc_ms_pass(philo->last_eat) >= philo->table->time_die)
			philo->is_alive = 0;
	}	
}

void	sleeping(t_philo *philo)
{
	struct timeval	start;
	long long int	diff;

	aff_philo(philo, 3);
	gettimeofday(&start, NULL);
	gettimeofday(&philo->last_eat, NULL);
	diff = calc_ms_pass(start);
	while (diff < philo->table->time_sleep && philo->table->stop == 0)
	{
		diff = calc_ms_pass(start);
		if (calc_ms_pass(philo->last_eat) >= philo->table->time_die)
			philo->is_alive = 0;
	}
	if (philo->table->stop == 0)
		aff_philo(philo, 4);
}
*/

void	*test_fct(void *arg)
{
	t_philo	*philo = (t_philo*)arg;
	while (philo->is_alive == 1 && philo->table->stop == 0)
	{
		if (philo->table->stop == 0)
		{
			fork_lock(philo);
			eat(philo);
			fork_unlock(philo);
		}
		if (philo->table->stop == 0)
			sleeping(philo);
		if (philo->is_alive == 0 && philo->table->stop == 0)
		{
			philo->table->stop = 1;
			aff_philo(philo, 5);
		}
	}
	printf("is_alive : %d\nstop : %d\n", philo->is_alive, philo->table->stop);
	return (NULL);
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

t_table	*init(char **av, int ac)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->lst = NULL;
	table->stop = 0;
	pthread_mutex_init(&table->txt, NULL);
	gettimeofday(&(table->time_start), NULL);
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
		usleep(5);
		tmp = tmp->next->next;
	}
	//sleep(1);
	pthread_join(test, NULL);
}