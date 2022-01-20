/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:09:03 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/19 11:09:35 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
