/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:35:20 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 13:45:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_info		ft_arg_xx(va_list *arg, char *type, int a)
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
	if ((nbr != 0 || info.precision != 0) && a == 1)
		ft_aff_nbr(info, ft_convert_base(nbr, "0123456789abcdef"));
	else if ((nbr != 0 || info.precision != 0) && a == 2)
		ft_aff_nbr(info, ft_convert_base(nbr, "0123456789ABCDEF"));
	else
		ft_aff_nbr(info, ft_strdup(""));
	return (info);
}

t_info		ft_arg_c(va_list *arg, char *type)
{
	char	*str;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	if (!(str = malloc(sizeof(char) * 2)))
		return (info);
	str[1] = '\0';
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	str[0] = va_arg(*arg, unsigned int);
	info.str = 1;
	if (str[0] == '\0')
		g_count++;
	if (str != 0 || info.precision != 0)
		ft_aff_nbr(info, str);
	return (info);
}

t_info		ft_arg_s(va_list *arg, char *type)
{
	char	*str;
	int		i;
	t_info	info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	str = ft_strdup(va_arg(*arg, char*));
	info.str = 2;
	if (!str)
	{
		free(str);
		str = ft_strdup("(null)");
	}
	if (str != 0 || info.precision != 0)
		ft_aff_str(info, str);
	return (info);
}

t_info		ft_arg_p(va_list *arg, char *type)
{
	unsigned long long int	nbr;
	int						i;
	t_info					info;

	i = 0;
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	nbr = va_arg(*arg, unsigned long long int);
	if (nbr != 0 || info.precision != 0)
		ft_aff_nbr(info, ft_convert_base_add(nbr, "0123456789abcdef"));
	return (info);
}

t_info		ft_arg_percent(va_list *arg, char *type)
{
	char	*str;
	int		i;
	t_info	info;

	i = 0;
	str = ft_strdup("%");
	info = ft_init_info();
	i += ft_take_flags(&info, type);
	i += ft_take_largeur(&info, type, i, arg);
	i += ft_take_precision(&info, type, i, arg);
	i += ft_take_flags(&info, type);
	ft_aff_percent(info, str);
	return (info);
}
