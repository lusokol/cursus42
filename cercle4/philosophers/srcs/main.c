/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:18:27 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/18 19:38:54 by lusokol          ###   ########.fr       */
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

long long int	calc_ms_pass(struct timeval start)
{
	struct timeval	end;
	long long int	diff;

	gettimeofday(&end, NULL);
	diff = ((end.tv_sec * 1000000 + end.tv_usec)
			- (start.tv_sec * 1000000 + start.tv_usec));
	diff /= 1000;
	return (diff);
}

void	color(int i)
{
	if (i == 1)
		write (1, "\e[0;49;96m", 10);
	else if (i == 2)
		write (1, "\e[0;49;92m", 10);
	else if (i == 3)
		write (1, "\e[0;49;95m", 10);
	else if (i == 4)
		write (1, "\e[0;49;33m", 10);
	else if (i == 5)
		write (1, "\e[0;49;91m", 10);
}

void	aff_philo(t_philo *philo, int i)
{
	char			*str;
	long long int	time;

	pthread_mutex_lock(&philo->table->txt);
	if (philo->table->stop == 0 || (philo->is_alive == 0 && i == 5))
	{
		write (1, "\e[38;5;208m[", 12);
		time = calc_ms_pass(philo->table->time_start);
		ft_putnbr(time);
		write (1, "ms]\e[0m", 7);
		if (time < 1000)
			write (1, "\t\t", 2);
		else
			write (1, "\t", 1);
		color(i);
		write (1, "Philosopher ", 12);
		ft_putnbr(philo->index);
		str = txt(i);
		write (1, str, strlen(str));
		write (1, "\e[0m", 4);
	}
	pthread_mutex_unlock(&philo->table->txt);
}

void	fork_lock(t_philo *philo)
{
	if (philo->index % 2)
	{
		pthread_mutex_lock(&(philo->prec->frk));
		aff_philo(philo, 1);
		pthread_mutex_lock(&(philo->next->frk));
		aff_philo(philo, 1);
	}
	else
	{
		pthread_mutex_lock(&(philo->next->frk));
		aff_philo(philo, 1);
		pthread_mutex_lock(&(philo->prec->frk));
		aff_philo(philo, 1);
	}
}

void	fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prec->frk);
	pthread_mutex_unlock(&philo->next->frk);
}

void	check_stop(t_table *table)
{
	int	i;

	i = 0;
	table->nb_eat_actual++;
	if (table->nb_philo == table->nb_eat_actual)
		table->stop = 1;
}

void	eat(t_philo *philo)
{
	struct timeval	start;
	long long int	diff;

	if (philo->table->stop == 0 && philo->is_alive == 1)
		aff_philo(philo, 2);
	philo->nb_eat++;
	if (philo->table->nb_eat != -1)
		if (philo->nb_eat == philo->table->nb_eat)
			check_stop(philo->table);
	gettimeofday(&start, NULL);
	gettimeofday(&philo->last_eat, NULL);
	diff = calc_ms_pass(start);
	while (diff < philo->table->time_eat
		&& philo->table->stop == 0 && philo->is_alive == 1)
	{
		usleep(100);
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
	diff = calc_ms_pass(start);
	while (diff < philo->table->time_sleep
		&& philo->table->stop == 0 && philo->is_alive == 1)
	{
		usleep(100);
		diff = calc_ms_pass(start);
		if (calc_ms_pass(philo->last_eat) >= philo->table->time_die)
			philo->is_alive = 0;
	}
}

void	*test_fct(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->start_eat == 0)
		;
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
		if (philo->table->stop == 0)
			aff_philo(philo, 4);
		if (philo->is_alive == 0 && philo->table->stop == 0)
		{
			philo->table->stop = 1;
			aff_philo(philo, 5);
		}
	}
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
	if (table->nb_philo == 1)
		ft_lstadd_back(&(table->lst), ft_lstnew(0, 2, table));
}

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
	philo = table->lst;
	while (++i <= table->nb_philo)
	{
		pthread_create(&philo->thrd, NULL, &test_fct, (void *)philo);
		philo = philo->next->next;
	}
	i = 0;
	gettimeofday(&(table->time_start), NULL);
	table->start_eat = 1;
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
	test = NULL;
	system ("leaks philosophers")̦
*/