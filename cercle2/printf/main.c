/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:36:53 by lusokol           #+#    #+#             */
/*   Updated: 2019/12/13 16:24:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

void	ft_printf(const char *test, ...);

int main(int ac, char **av)
{
	(void)ac;
	char *str = "chiffre 15 : |%*.*d|\n";
	printf("precision : 10, largeur : 15\n");
	printf("printf :\n");
	printf(str, 15, 10, 15);
	printf("ft_printf :\n");
	ft_printf(str, 15, 10, 15);
	return 0;
}
