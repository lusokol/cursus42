/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:23:07 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 15:48:13 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_check_flag(char a)
{
	if (a == '-' || a == '0')
		return (1);
	return (0);
}

void	ft_aff_moins(char *nbr, t_printf *info)
{
	if (nbr[0] == '-')
	{
		ft_putchar('-');
		g_count++;
	}
	if (info->str == 4)
	{
		ft_putstr("0x");
		g_count += 2;
	}
}

void	ft_aff_nbrstr(char *nbr, t_printf *info)
{
	int i;

	i = (nbr[0] == '-' && info->str == 0) ? 1 : 0;
	if (info->str == 1 && nbr[0] == '\0')
		ft_putchar(0);
	while (nbr[i])
	{
		if (info->str > 0 && i >= info->precision && info->precision != -1
				&& info->str != 4)
			break ;
		if (nbr[i] != '\0')
		{
			ft_putchar(nbr[i]);
			g_count++;
		}
		i++;
	}
}

int		ft_nbr_zero(t_printf *info, char *nbr)
{
	int zero;

	zero = info->precision - ft_strlen(nbr) + ((nbr[0] == '-') ? 1 : 0);
	zero = (zero < 0) ? 0 : zero;
	return (zero);
}

int		ft_nbr_espace(t_printf *info, char *nbr, int zero)
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
	if (info->str == 4)
		espace -= 2;
	espace = (espace < 0) ? 0 : espace;
	return (espace);
}
