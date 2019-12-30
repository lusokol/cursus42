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
	int a = -123;
	printf("|%u|\n", -1001234);
	ft_printf("|%u|\n", -1001234);
	(void)ac;
	//char *str = "|%010d|";
	//printf(str, -741);
	//printf("\n");
	//ft_printf(str, -741);
	return 0;
}
