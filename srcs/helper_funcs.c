/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:18:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/13 11:19:56 by hlibine          ###   ########.fr       */
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