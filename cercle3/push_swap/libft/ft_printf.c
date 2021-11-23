/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:13 by lusokol           #+#    #+#             */
/*   Updated: 2021/11/23 12:09:01 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int g_count;

int	ft_take_flags(t_info *info, char *type)
{
	int	i;

	i = 0;
	while (ft_check_flag(type[i]))
	{
		if (type[i] == '-')
			info->moins = 1;
		if (type[i] == '0')
			info->zeros = 1;
		i++;
	}
	return (i);
}

int	ft_print_arg(va_list *arg, char *type)
{
	int	len;

	len = ft_strlen(type) - 1;
	if (type[len] == 'd' || type[len] == 'i')
		ft_arg_i_d(arg, type);
	else if (type[len] == 'c')
		ft_arg_c(arg, type);
	else if (type[len] == 's')
		ft_arg_s(arg, type);
	else if (type[len] == 'x')
		ft_arg_xx(arg, type, 1);
	else if (type[len] == 'X')
		ft_arg_xx(arg, type, 2);
	else if (type[len] == 'p')
		ft_arg_p(arg, type);
	else if (type[len] == 'u')
		ft_arg_u(arg, type);
	else if (type[len] == '%')
		ft_arg_percent(arg, type);
	return (1);
}

char	*ft_search_arg(const char *str, int i)
{
	int			tmp;
	char		*type;

	tmp = 1;
	while (str[i + tmp] && !ft_istype(str[i + tmp]))
		tmp++;
	type = ft_substr(str + 1, i, tmp);
	return (type);
}

int	ft_printchar(const char *str, int i)
{
	while (str[i] != '%' && str[i])
	{
		ft_putchar(str[i++]);
		g_count++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	char	*type;
	int		i;

	g_count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		i = ft_printchar(str, i);
		if (str[i] == '%')
		{
			type = ft_search_arg(str, i);
			ft_print_arg(&arg, type);
			i += ft_strlen(type);
			free(type);
		}
		if (str[i])
			i++;
	}
	va_end(arg);
	return (g_count);
}
