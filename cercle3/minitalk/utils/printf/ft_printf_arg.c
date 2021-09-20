/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:05:45 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 13:37:59 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_take_arg(va_list *arg, char *type, int i)
{
	int nbr;

	nbr = 0;
	if (type[i] == '*')
		return (va_arg(*arg, int));
	while (ft_isdigit(type[i]))
	{
		nbr = (nbr * 10) + (type[i] - '0');
		i++;
	}
	return (nbr);
}

int			ft_take_largeur(t_info *info, char *type, int i, va_list *arg)
{
	int add;

	add = 0;
	if (type[i + add] != '.' && (ft_isdigit(type[i + add]) ||
				type[i + add] == '*'))
	{
		info->largeur = ft_take_arg(arg, type, i + add);
		if (type[i + add] == '*')
			add++;
		else
			while (ft_isdigit(type[i + add]))
				add++;
	}
	if (info->largeur < 0)
	{
		info->moins = 1;
		info->largeur = -info->largeur;
	}
	return (add);
}

int			ft_take_precision(t_info *info, char *type, int i, va_list *arg)
{
	int add;

	add = 0;
	if (type[i + add] == '.')
	{
		add++;
		info->precision = ft_take_arg(arg, type, i + add);
		if (type[i + add] == '*')
			add++;
		else
			while (ft_isdigit(type[i + add]))
				add++;
		if (info->precision >= 0)
			info->zeros = 0;
	}
	return (add);
}

t_info		ft_arg_i_d(va_list *arg, char *type)
{
	int		nbr;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, int);
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_itoa(nbr));
	else
		while (info.largeur > 0)
		{
			ft_putchar(' ');
			g_count++;
			info.largeur--;
		}
	return (info);
}

t_info		ft_arg_u(va_list *arg, char *type)
{
	int long long		nbr;
	int					i;
	t_info				info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, int);
	if (nbr < 0)
		nbr = (4294967296) - -nbr;
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_itoa(nbr));
	else
		ft_aff_nbr(info, ft_strdup(""));
	return (info);
}
