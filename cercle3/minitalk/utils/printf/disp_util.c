/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:20:06 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 15:38:13 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		if (info.str == 0 || info.str == 4)
			ft_aff_moins(nbr, &info);
		ft_aff_zeroes(espace);
	}
	else if (info.str == 0 || info.str == 4)
		ft_aff_moins(nbr, &info);
	ft_aff_zeroes(zero);
	ft_aff_nbrstr(nbr, &info);
	if (info.moins == 1)
		ft_aff_spaces(espace);
	free(nbr);
}

void	ft_aff_str(t_info info, char *str)
{
	int espace;
	int zero;

	info.precision = (info.precision < -1) ? -1 : info.precision;
	info.largeur = (info.largeur == 0) ? -1 : info.largeur;
	zero = ft_nbr_zero(&info, str);
	espace = ft_nbr_espace(&info, str, 0);
	if (info.zeros == 1 && (info.str == 3 || ((info.str == 2 || info.str == 4) && info.moins == 0)))
		ft_aff_zeroes(espace);
	else if (info.moins == 0)
		ft_aff_spaces(espace);
	if (info.zeros == 0 && info.str == 4)
		ft_aff_moins(str, &info);
	if (info.zeros == 0 && info.str == 4)
		ft_aff_zeroes(zero);
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
	if (info.moins == 1)
		ft_aff_spaces(espace);
	free(str);
}
