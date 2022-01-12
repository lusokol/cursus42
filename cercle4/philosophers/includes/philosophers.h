/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:33:45 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/12 18:11:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

#include <string.h>

/* 
** to_do values :
** 1 = eat
** 2 = sleep
** 3 = think
**
** type :
** 1 = philo
** 2 = fork
*/

typedef struct	s_philo
{
	int				type;
	int				to_do;
	int				index;
	pthread_mutex_t	frk;
	struct timeval	last_eat;
	int				is_alive;
	int				is_eating;
	struct s_table	*table;
	struct s_philo	*next;
	struct s_philo	*prec;
}					t_philo;

typedef struct	s_table
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				stop;
	pthread_mutex_t	txt;
	struct timeval	time_start;
	t_philo			*lst;
}					t_table;

int		ft_atoi(const char *str);
t_philo	*ft_lstnew(int i, int j, t_table *table);
void	ft_lstadd_back(t_philo **alst, t_philo *new);

#endif
