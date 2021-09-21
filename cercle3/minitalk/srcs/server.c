/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:28:49 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 15:20:23 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** ideal for usleep for me :
** server : 10 (line 19)
** client : 20 (line 171)
*/

void	convert_charr(char str, int convert, siginfo_t *siginfo)
{
	static int	count;
	static char	a;

	usleep(10);
	if (convert == 0)
	{
		count = 7;
		a = 0;
		return ;
	}
	if (str == '1')
		a = a | (1 << count);
	count--;
	if (count < 0)
	{
		count = 7;
		ft_printf("%c", a);
		a = 0;
	}
	if (siginfo)
		kill(siginfo->si_pid, SIGUSR1);
}

void	catcher1(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	convert_charr('0', 1, siginfo);
}

void	catcher2(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	convert_charr('1', 1, siginfo);
}

int	main(int ac, char **av)
{
	struct sigaction	act1;
	struct sigaction	act2;

	(void)ac;
	(void)av;
	act1.sa_sigaction = &catcher1;
	act1.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act1, NULL) < 0)
	{
		perror ("sigaction");
		return (1);
	}
	act2.sa_sigaction = &catcher2;
	act2.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &act2, NULL) < 0)
	{
		perror ("sigaction");
		return (1);
	}
	convert_charr('0', 0, 0);
	ft_printf("\e[38;5;164m[SERVER] - pid : %d\n\e[0m\n", getpid());
	while (1)
		pause();
	return (0);
}
