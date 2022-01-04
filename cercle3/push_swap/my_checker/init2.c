/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:23:59 by macbookpro        #+#    #+#             */
/*   Updated: 2022/01/04 17:35:02 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

long long int	ft_latoi(char *str)
{
	int				i;
	int				negative;
	long long int	res;

	i = 0;
	negative = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = negative * -1;
		i++;
	}
	while ((ft_isdigit(str[i])) && str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * negative);
}

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
