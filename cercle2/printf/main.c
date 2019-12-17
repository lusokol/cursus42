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
	char *str = "chiffre 15 : |%*.*d|\nchiffre2 123456 : |%*.*d|\n";
	printf("printf :\n");
	printf(str, 5, 10, 15, 15, 20, 123456);
	printf("ft_printf :\n");
	ft_printf(str, 5, 10, 15, 15, 20, 123456);
	return 0;
}
