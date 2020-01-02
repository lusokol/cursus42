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
			a == 'x' || a == 'X' || a == 'p' || a == 'u' || a == '%')
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

void	ft_aff_nbrstr(char *nbr, t_info *info)
{
	int i;

	i = (nbr[0] == '-' && info->str == 0) ? 1 : 0;
	if (info->str == 1 && nbr[0] == '\0')
		ft_putchar(0);
	while (nbr[i])
	{
		if (info->str > 0 && i >= info->precision && info->precision != -1)
				break ;
		if (nbr[i] != '\0')
		{
			ft_putchar(nbr[i]);
			g_count++;
		}
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

int		ft_nbr_espace(t_info *info, char *nbr, int zero)
{
	int espace;

	espace = info->largeur - ft_strlen(nbr) - zero;
	if (info->str == 1 && nbr[0] == '\0')
		espace--;
	if (info->str == 2 && info->precision != -1)
	{
		if (info->precision < ft_strlen(nbr))
			espace = info->largeur - info->precision;
		else
			espace = info->largeur - ft_strlen(nbr);
	}
	espace = (espace < 0) ? 0 : espace;
	return (espace);
}

void	ft_aff_nbr(t_info info, char *nbr)
{
	int espace;
	int zero;

	zero = ft_nbr_zero(&info, nbr);
	espace = ft_nbr_espace(&info, nbr, zero);
	if (info.str == 1)
		espace += zero;
	if (info.str == 1)
		zero = 0;
	if (info.moins == 0 && info.zeros == 0)
		ft_aff_spaces(espace);
	if (info.moins == 0 && info.zeros == 1)
	{
		if (info.str == 0)
			ft_aff_moins(nbr);
		ft_aff_zeroes(espace);
	}
	else
		if (info.str == 0)
			ft_aff_moins(nbr);
	ft_aff_zeroes(zero);
	ft_aff_nbrstr(nbr, &info);
	if (info.moins == 1)
		ft_aff_spaces(espace);
	free(nbr);
}

void	ft_aff_str(t_info info, char *str)
{
	int espace;

	info.precision = (info.precision < -1) ? -1 : info.precision;
	info.largeur = (info.largeur == 0) ? -1 : info.largeur;
	espace = ft_nbr_espace(&info, str, 0);
	if (info.zeros == 1 && info.str == 3)
		ft_aff_zeroes(espace);
	else if (info.moins == 0)
		ft_aff_spaces(espace);
	ft_aff_nbrstr(str, &info);
	if (info.moins == 1)
		ft_aff_spaces(espace);
	free(str);
}

void	ft_aff_percent(t_info info, char *str)
{
	int espace;

	info.precision = -1;
	espace = (info.largeur - 1 >= 0) ? info.largeur - 1 : 0;
	if (info.zeros == 1 && info.moins == 0)
		ft_aff_zeroes(espace);
	if (info.zeros == 0 && info.moins == 0)
		ft_aff_spaces(espace);
	ft_putchar('%');
	g_count++;
	if (info.zeros == 0 && info.moins == 1)
		ft_aff_spaces(espace);
	if (info.zeros == 1 && info.moins == 1)
		ft_aff_zeroes(espace);
	free(str);
}
