/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:23:59 by macbookpro        #+#    #+#             */
/*   Updated: 2022/01/04 11:38:47 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ret_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	check_two(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '+' || av[1][i] == '-')
		{
			i++;
			if (!av[1][i] || !ft_isdigit(av[1][i]))
				return (ret_error());
		}
		if (!ft_isdigit(av[1][i]))
			return (ret_error());
		while (ft_isdigit(av[1][i]))
			i++;
		if (av[1][i] != '\0' && av[1][i] != ' ')
			return (ret_error());
		while (av[1][i] == ' ')
			i++;
	}
	return (1);
}

int	check_two_plus(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		if (av[j][i] == '+' || av[j][i] == '-')
		{
			i++;
			if (!av[j][i] || !ft_isdigit(av[j][i]))
				return (ret_error());
		}
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]))
				return (ret_error());
			i++;
		}
		j++;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (ac == 1)
		return (0);
	if (ac == 2)
		if (!check_two(av))
			return (0);
	if (ac > 2)
		if (!check_two_plus(av))
			return (0);
	return (1);
}
