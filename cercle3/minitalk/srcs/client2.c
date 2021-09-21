/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:26:26 by macbookpro        #+#    #+#             */
/*   Updated: 2021/09/21 13:36:10 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	bad_init(void)
{
	ft_printf("\e[38;5;196mNeed 3 arguments : \e[38;5;208m\
./client [pid] [string]\n\e[0m");
	return (0);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("\e[38;5;196mYou gave an invalid PID,\
 it must be only digit !\e[0m\n");
			return (0);
		}
		i++;
	}
	return (1);
}
