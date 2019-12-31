/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:49:13 by lusokol           #+#    #+#             */
/*   Updated: 2019/12/16 15:30:46 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_arg(va_list *arg, char *type)
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
		ft_arg_xX(arg, type, 1);
	else if (type[len] == 'X')
		ft_arg_xX(arg, type, 2);
	else if (type[len] == 'p') // adresse en hexa
		ft_arg_p(arg, type);
	else if (type[len] == 'u')
		ft_arg_u(arg, type);
	else if (type[len] == '%')
		ft_arg_percent(arg, type);
	return (1);
}

char	*ft_search_arg(const char *str)
{
	static int	index;
	int			i;
	int			j;
	int			tmp;
	char		*type;

	j = 0;
	i = 0;
	if (!index)
		index = 1;
	while (index - i > 0 && str[j])
	{
		tmp = 0;
		if (str[j] && str[j] == '%')
		{
			while (str[j + tmp] && !ft_istype(str[j + tmp]))
				tmp++;
			type = ft_substr(str + 1, j, tmp);
			i++;
		}
		j++;
	}
	index++;
	return (type);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	char	*type;
	int		i;
	int		j;

	g_count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		j = 0;
		while (str[i] != '%' && str[i])
		{
			ft_putchar(str[i++]);
			g_count++;
		}
		if (str[i] == '%')
		{
			type = ft_search_arg(str);
			ft_print_arg(&arg, type);
		}
		while (!ft_istype(str[i]) && str[i])
			i++;
		if (str[i])
			i++;
	}
	va_end(arg); 
	return (g_count);
}
