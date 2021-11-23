/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:37:53 by lusokol           #+#    #+#             */
/*   Updated: 2021/10/14 14:58:05 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	g_count;

typedef struct s_info
{
	int			precision;
	int			largeur;
	int			moins;
	int			zeros;
	int			str;
}				t_info;

int				ft_printf(const char *str, ...);
int				ft_istype(char a);
t_info			ft_init_info(void);
void			ft_aff_zeroes(int a);
void			ft_aff_spaces(int a);
int				ft_check_flag(char a);
void			ft_aff_nbr(t_info info, char *nbr);
void			ft_aff_str(t_info info, char *str);
t_info			ft_arg_u(va_list *arg, char *type);
t_info			ft_arg_c(va_list *arg, char *type);
t_info			ft_arg_s(va_list *arg, char *type);
t_info			ft_arg_p(va_list *arg, char *type);
int				ft_nbr_zero(t_info *info, char *nbr);
t_info			ft_arg_i_d(va_list *arg, char *type);
void			ft_aff_moins(char *nbr, t_info *info);
void			ft_aff_nbrstr(char *nbr, t_info *info);
void			ft_disp_arg(t_info info, char *todisp);
void			ft_aff_percent(t_info info, char *str);
int				ft_take_flags(t_info *info, char *type);
t_info			ft_arg_percent(va_list *arg, char *type);
t_info			ft_arg_xx(va_list *arg, char *type, int a);
int				ft_nbr_espace(t_info *info, char *nbr, int zero);
char			*ft_convert_base(unsigned int nbr, char *baseto);
char			*ft_convert_base_add(unsigned long long int nbr, char *baseto);
int				ft_take_largeur(t_info *info, char *type, int i, va_list *arg);
int				ft_take_precision(t_info *info, char *type,
					int i, va_list *arg);

#endif
