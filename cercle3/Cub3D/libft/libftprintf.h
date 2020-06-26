/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:37:53 by lusokol           #+#    #+#             */
/*   Updated: 2020/01/07 15:03:03 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <unistd.h>

int g_count;

typedef struct	s_printf
{
	int			precision;
	int			largeur;
	int			moins;
	int			zeros;
	int			str;
}				t_printf;

int				ft_istype(char a);
t_printf		ft_init_printf(void);
void			ft_aff_zeroes(int a);
void			ft_aff_spaces(int a);
int				ft_check_flag(char a);
int				ft_printf(const char *str, ...);
void			ft_aff_nbr(t_printf info, char *nbr);
void			ft_aff_str(t_printf info, char *str);
t_printf		ft_arg_u(va_list *arg, char *type);
t_printf		ft_arg_c(va_list *arg, char *type);
t_printf		ft_arg_s(va_list *arg, char *type);
t_printf		ft_arg_p(va_list *arg, char *type);
int				ft_nbr_zero(t_printf *info, char *nbr);
t_printf		ft_arg_i_d(va_list *arg, char *type);
void			ft_aff_moins(char *nbr, t_printf *info);
void			ft_aff_nbrstr(char *nbr, t_printf *info);
void			ft_disp_arg(t_printf info, char *todisp);
void			ft_aff_percent(t_printf info, char *str);
int				ft_take_flags(t_printf *info, char *type);
t_printf		ft_arg_percent(va_list *arg, char *type);
t_printf		ft_arg_xx(va_list *arg, char *type, int a);
int				ft_nbr_espace(t_printf *info, char *nbr, int zero);
char			*ft_convert_base(unsigned int nbr, char *baseto);
char			*ft_convert_base_add(unsigned long long int nbr, char *baseto);
int				ft_take_largeur(t_printf *info, char *type, int i,
		va_list *arg);
int				ft_take_precision(t_printf *info, char *type, int i,
		va_list *arg);

#endif
