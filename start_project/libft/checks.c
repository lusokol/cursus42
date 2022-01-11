/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 13:23:07 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 12:52:50 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_flag(char a)
{
	if (a == '-' || a == '0')
		return (1);
	return (0);
}

void	ft_aff_moins(char *nbr, t_info *info)
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

void	ft_aff_nbrstr(char *nbr, t_info *info)
{
	int	i;

	if (nbr[0] == '-' && info->str == 0)
		i = 1;
	else
		i = 0;
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

int	ft_nbr_zero(t_info *info, char *nbr)
{
	int	zero;

	if (nbr[0] == '-')
		zero = info->precision - ft_strlen(nbr) + 1;
	else
		zero = info->precision - ft_strlen(nbr);
	if (zero < 0)
		zero = 0;
	return (zero);
}

int	ft_nbr_espace(t_info *info, char *nbr, int zero)
{
	int	espace;

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
	if (espace < 0)
		espace = 0;
	return (espace);
}
