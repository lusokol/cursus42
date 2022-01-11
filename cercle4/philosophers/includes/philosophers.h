/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:33:45 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/11 18:17:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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
	int	type;
	int	to_do;
	int	index;
	struct s_philo *next;
	struct s_philo *prec;
}				t_philo;

typedef struct	s_table
{
	int		nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		nb_eat;
	t_philo	*lst;
}				t_table;

int		ft_atoi(const char *str);
t_philo	*ft_lstnew(int i, int j);
void	ft_lstadd_back(t_philo **alst, t_philo *new);

#endif
