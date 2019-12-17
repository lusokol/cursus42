/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:37:53 by lusokol           #+#    #+#             */
/*   Updated: 2019/12/13 14:54:28 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
typedef struct	s_info
{
	int			precision;
	int			largeur;
	int			moins;
	int			zeros;
}				t_info;
t_info	ft_arg_i_d(va_list *arg, char *type);
int		ft_istype(char a);
int		ft_check_flag(char a);
void	ft_disp_arg(int largeur, int precision, char *toDisp, int type);

#endif
