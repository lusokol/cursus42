/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:10:24 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 14:59:54 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_info		ft_init_info(void)
{
	t_info info;

	info.precision = -1;
	info.largeur = 0;
	info.moins = 0;
	info.zeros = 0;
	info.str = 0;
	return (info);
}

int			ft_len_nbr(unsigned long long int nb, int lenbase)
{
	int i;

	i = 0;
	while (nb >= (unsigned long long int)lenbase)
	{
		nb = nb / lenbase;
		i++;
	}
	i++;
	return (i);
}

char		*ft_convert_base_add(unsigned long long int nbr, char *baseto)
{
	int		len;
	char	*nb;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_len_nbr(nbr, ft_strlen(baseto));
	if (!(nb = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nb[len] = '\0';
	while (nbr >= (unsigned long long int)ft_strlen(baseto))
	{
		nb[len - i] = baseto[nbr % ft_strlen(baseto)];
		nbr = nbr / ft_strlen(baseto);
		i++;
	}
	nb[len - i] = baseto[nbr % ft_strlen(baseto)];
	return (nb);
}

char		*ft_convert_base(unsigned int nbr, char *baseto)
{
	int		len;
	char	*nb;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (nbr < 0)
		nbr = (4294967296) - -nbr;
	len = ft_len_nbr(nbr, ft_strlen(baseto));
	if (!(nb = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nb[len] = '\0';
	while (nbr > (unsigned int)ft_strlen(baseto))
	{
		nb[len - i] = baseto[nbr % ft_strlen(baseto)];
		nbr = nbr / ft_strlen(baseto);
		i++;
	}
	nb[len - i] = baseto[nbr % ft_strlen(baseto)];
	return (nb);
}

int			ft_istype(char a)
{
	if (a == 'd' || a == 'i' || a == 'c' || a == 's' ||
			a == 'x' || a == 'X' || a == 'p' || a == 'u' || a == '%')
		return (1);
	return (0);
}
