/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   logic_sort.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: macbookpro <macbookpro@student.42.fr>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/07 11:33:47 by lusokol		   #+#	#+#			 */
/*   Updated: 2021/12/16 10:50:49 by macbookpro	   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

/* ICI pour opti ce que j'envoie dans b au debut */

void	calc_merge(t_sort *tmp)
{
	t_nbr	*b;

	b = tmp->b;
	while (b)
	{
		find_higher(b->index, tmp->a, b);
		b = b->next;
	}
}

/* faire un algo de backtracking
** qui genere pour chaque chiffre parmis les size/2 premiers de la liste.
** des rayons qui partent respectivement sur les 5 premiers chiffres
** suivant celui de depart
** et ce jusqu'a la fin
*/

// Gerer les doublons et la redirection vers la bonne 
// fonction (backtracking ou logic sort)

void	check_move(t_sort *tmp, t_all *all)
{
	(void)all;
	calc_up_a(tmp);
	calc_up_b(tmp);
	calc_merge(tmp);
}

void	logic_sort(t_all *all)
{
	t_sort	*tmp;

	tmp = all->qs;
	push_b(all->qs);
	while (tmp->b)
	{
		check_move(tmp, all);
		best_move(tmp);
	}
	last_rotation(tmp);
}
