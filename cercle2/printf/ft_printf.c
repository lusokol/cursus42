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
		ft_putchar(va_arg(*arg, int));
	else if (type[len] == 's')
		ft_putstr(va_arg(*arg, char *));
	else if (type[len] == 'x') // hexa em minuscule
		ft_putstr(va_arg(*arg, char *));
	else if (type[len] == 'X') // hexa en majuscule
		ft_putstr(va_arg(*arg, char *));
	else if (type[len] == 'p') // adresse en hexa
		ft_putstr(va_arg(*arg, char *));
	else if (type[len] == 'u') // valeur absolue
		ft_arg_u(arg, type);
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

/**********************************************************************************

A FAIRE : VERIFIER LA VARIABLE GLOBALE, VALEUR DE RETOUR, ET "INT" FT_PRINTFT

  1 = int
  2 = char
  3 = string
  4 = ....

flags :
  %-d
  %0d

largeur :
  %8d
  %*d -> cherche avec va_arg

precision :
  %.6d
  %.*d -> chercher avec va_arg

largeur : nombre de char a aff
precision : nombre min de char de l'arg a afficher“

**********************************************************************************/
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
		//ft_putstr("test1");
		if (str[i] == '%')
		{
			type = ft_search_arg(str);
			ft_print_arg(&arg, type);
		}
		//j = ft_printf_type(&arg, type);
		while (!ft_istype(str[i]) && str[i])
			i++;
		if (str[i])
			i++;
	}
	va_end(arg); 
	//printf("g_count : %d\n", g_count);
	return (g_count);
}
