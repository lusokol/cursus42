/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:05:52 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/20 18:08:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->prec->frk);
	pthread_mutex_unlock(&philo->next->frk);
}

void	fork_lock(t_philo *philo)
{
	philo->is_waiting = 1;
	pthread_mutex_lock(&(philo->prec->frk));
	aff_philo(philo, 1);
	pthread_mutex_lock(&(philo->next->frk));
	aff_philo(philo, 1);
	philo->is_waiting = 0;
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
	if (philo->table->stop == 0)
		aff_philo(philo, 4);
}

void	*routine_fct(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->table->start_eat == 0)
		;
	if (!(philo->index % 2))
		usleep(philo->table->time_eat * 1000 / 2 + 1);
	gettimeofday(&philo->last_eat, NULL);
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
	return (NULL);
}
