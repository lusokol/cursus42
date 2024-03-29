/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:29:49 by lusokol           #+#    #+#             */
/*   Updated: 2022/01/12 15:00:35 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

clock_t	g_begin;

char	take_char(char *str, int tostock)
{
	static char	*string;
	static int	i;

	if (tostock)
	{
		string = str;
		i = 0;
	}
	else
	{
		if (string[i])
			return (string[i++]);
	}
	return (0);
}

int	to_send(int tostock)
{
	static char	a;
	static int	i;

	if (tostock || i < 0)
	{
		i = 7;
		a = take_char("", 0);
		if (!a)
			return (-1);
	}
	if (!tostock)
	{
		if (a & (1 << i--))
			return (1);
		else
			return (0);
	}
	return (0);
}

int	take_pid(int i, int swap)
{
	static int	a;

	if (swap == 1)
		a = i;
	else if (swap == 0)
		return (a);
	return (-1);
}

void	catcher(int sig)
{
	int	i;

	(void)sig;
	i = to_send(0);
	usleep(20);
	if (i == 1)
		kill(take_pid(0, 0), SIGUSR2);
	else if (i == 0)
		kill(take_pid(0, 0), SIGUSR1);
	if (i == -1)
	{
		ft_printf("\e[38;5;118mThe string has been correctly sent and \
receive in the process %d.\n\e[0m", take_pid(0, 0));
		exit(0);
	}
	g_begin = clock();
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;

	if (ac != 3)
		return (bad_init());
	if (!ft_strisdigit(av[1]))
		return (0);
	str = ft_strjoin(ft_strdup(av[2]), ft_strdup("\n"));
	take_pid(ft_atoi(av[1]), 1);
	take_char(str, 1);
	to_send(1);
	catcher(0);
	signal(SIGUSR1, catcher);
	signal(SIGUSR2, catcher);
	g_begin = clock();
	while (1)
	{
		i = (clock() - g_begin) * 1000 / CLOCKS_PER_SEC;
		if (i > 1000)
		{
			ft_printf("\e[38;5;196mSignal lost, stopping the transfer...\
\nPlease restart the server.\n\e[0m");
			exit(0);
		}
	}
	free(str);
}
