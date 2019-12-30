/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:23:07 by lusokol           #+#    #+#             */
/*   Updated: 2019/12/13 13:27:40 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_flag(char a)
{
	if (a == '-' || a == '0')
		return (1);
	return (0);
}

int		ft_istype(char a)
{
	if (a == 'd' || a == 'i' || a == 'c' || a == 's' ||
			a == 'x' || a == 'X' || a == 'p' || a == 'u')
		return (1);
	return (0);
}

void	ft_aff_spaces(int a)
{
	while (a > 0)
	{
		ft_putchar(' ');
		g_count++;
		a--;
	}
}

void	ft_aff_zeroes(int a)
{
	while (a > 0)
	{
		ft_putchar('0');
		g_count++;
		a--;
	}
}

void	ft_aff_moins(char *nbr)
{
	if (nbr[0]  == '-')
	{
		ft_putchar('-');
		g_count++;
	}
}

void	ft_aff_nbrstr(char *nbr)
{
	int i;

	i = (nbr[0] == '-') ? 1 : 0;
	while (nbr[i])
	{
		ft_putchar(nbr[i]);
		g_count++;
		i++;
	}
}

int		ft_nbr_zero(t_info *info, char *nbr)
{
	int zero;

	zero = info->precision - ft_strlen(nbr) + ((nbr[0] == '-')  ? 1 : 0);
	zero = (zero < 0) ? 0 : zero;
	return (zero);
}

int		ft_nbr_espace(t_info *info, char *nbr)
{
	int espace;
	int zero;

	espace = 0;
	zero = 0;
	if (info->precision < info->largeur)
	{
		espace = info->largeur - ((ft_strlen(nbr) > info->precision) ? ft_strlen(nbr) : info->precision);
		if (info->precision > ft_strlen(nbr))
			zero = info->precision - ft_strlen(nbr) + ((nbr[0] == '-')  ? 1 : 0);
		if (zero < 0)
			espace -= zero;
	}
	espace = (espace < 0) ? 0 : espace;
	return (espace);
}

void	ft_aff_nbr(t_info info, char *nbr)
{
	int espace;
	int zero;

	espace = ft_nbr_espace(&info, nbr);
	zero = ft_nbr_zero(&info, nbr);
	if (info.moins == 0 && info.zeros == 0)
		ft_aff_spaces(espace);
	if (info.moins == 0 && info.zeros == 1)
	{
		ft_aff_moins(nbr);
		ft_aff_zeroes(espace);
	}
	else
		ft_aff_moins(nbr);
	ft_aff_zeroes(zero);
	ft_aff_nbrstr(nbr);
	if (info.moins == 1)
			ft_aff_spaces(espace);
	free(nbr);
}
