/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:04:07 by macbookpro        #+#    #+#             */
/*   Updated: 2021/10/09 17:10:01 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isfloat(char *str)
{
	int	i;

	i = 0;
	if (str && str[i] == '-')
		i++;
	while (str && str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (str && str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

long double	ft_atof(const char *str)
{
	int			i;
	int			negative;
	long double	res;
	int			dot;

	i = 0;
	negative = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negative = negative * -1;
	while ((ft_isdigit(str[i])) && str[i] != '\0')
		res = res * 10 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		dot = 10;
		while ((ft_isdigit(str[i])) && str[i] != '\0')
		{
			res = res + ((long double)(str[i++] - '0') / dot);
			dot *= 10;
		}
	}
	return (res * negative);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	my_rgb(int r1, int g1, int b1)
{
	int		nbr;
	int		i;
	int		j;
	char	tmp;

	nbr = 0;
	i = 0;
	while (i < 24)
	{
		if (i < 8)
			tmp = b1;
		else if (i >= 8 && i < 16)
			tmp = g1;
		else if (i >= 16 && i < 24)
			tmp = r1;
		j = 0;
		while (j < 8)
		{
			if (tmp & (1 << j))
				nbr = nbr | (1 << i);
			i++;
			j++;
		}
	}
	return (nbr);
}
