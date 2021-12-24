/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:34:54 by macbookpro        #+#    #+#             */
/*   Updated: 2021/12/24 18:41:47 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

typedef struct s_nbr
{
	int				nbr;
	int				index;
	int				move;
	int				move_a;
	int				move_b;
	int				sens;
	int				sens_a;
	int				push_b;
	struct s_nbr	*next;
}	t_nbr;

typedef struct s_backtrack
{
	int					in_a;
	int					in_b;
	int					*actual;
	struct s_backtrack	**tab;
}	t_backtrack;

typedef struct s_sort
{
	t_nbr	*a;
	t_nbr	*b;
}	t_sort;

typedef struct s_plsc
{
	int	lm;
	int	m;
	int	*tab;
	int	*s;
	int	max;
}	t_plsc;

typedef struct s_all
{
	int			iteration_max;
	int			print;
	int			size;
	int			ac;
	char		**tab;
	char		**act;
	int			*nbr;
	t_sort		*original;
	t_sort		*qs;
	t_nbr		*copy;
	t_backtrack	*first;
	int			*result;
}	t_all;

void		ft_sa(t_nbr **a, t_nbr **b, int print);
void		ft_sb(t_nbr **a, t_nbr **b, int print);
void		ft_ss(t_nbr **a, t_nbr **b, int print);
void		ft_pa(t_nbr **a, t_nbr **b, int print);
void		ft_pb(t_nbr **a, t_nbr **b, int print);
void		ft_ra(t_nbr **a, t_nbr **b, int print);
void		ft_rb(t_nbr **a, t_nbr **b, int print);
void		ft_rr(t_nbr **a, t_nbr **b, int print);
void		ft_rra(t_nbr **a, t_nbr **b, int print);
void		ft_rrb(t_nbr **a, t_nbr **b, int print);
void		ft_rrr(t_nbr **a, t_nbr **b, int print);
t_all		*lst_init(int ac, char **av);
void		create_lst(t_all *all);
int			check_double(t_nbr *lst);
t_nbr		*ft_lstnew2(int nbr, int index);
void		ft_lstadd_back2(t_nbr **alst, t_nbr *new);
void		ft_lst_free(t_nbr *lst);
void		read_arg(t_all *lst);
int			check_arg(int ac, char **av);
void		ft_swap_lst(t_nbr *lst1, t_nbr *lst2);
void		ft_free_all(t_all *lst, int i);

#endif