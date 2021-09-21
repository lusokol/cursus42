/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:22:28 by lusokol           #+#    #+#             */
/*   Updated: 2021/09/20 14:14:26 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear2(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*pmt;

	pmt = *lst;
	while (pmt != NULL)
	{
		tmp = pmt->next;
		del(pmt->content);
		free(pmt);
		pmt = tmp;
	}
	*lst = NULL;
}

static t_list	*ft_lstnew2(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = ft_lstnew2((*f)(lst->content));
	if (!tmp)
		return (0);
	begin = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew2((*f)(lst->content));
		if (!tmp->next)
		{
			ft_lstclear2(&begin, del);
			return (0);
		}
		tmp = tmp->next;
	}
	return (begin);
}
