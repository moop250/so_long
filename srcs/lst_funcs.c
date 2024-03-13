/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:18:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/13 22:27:13 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sl	*sl_lstnew(t_xmp *content)
{
	t_sl	*node;

	node = galloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_sl	*sl_lstlast(t_sl *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	sl_lstadd_back(t_sl **lst, t_sl *new)
{
	if (!*lst)
		*lst = new;
	else
		sl_lstlast(*lst)->next = new;
	return ;
}

t_pointll	*sl_lstnewpoint(t_point *content)
{
	t_pointll	*node;

	node = galloc(sizeof(t_pointll));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	sl_lstadd_front(t_pointll **lst, t_pointll *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		printf("i should be called once\n");
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
	return ;
}