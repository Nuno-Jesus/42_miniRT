/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:53 by marvin            #+#    #+#             */
/*   Updated: 2023/05/18 15:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_list	*nc_list_map(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list2;
	t_list	*node;

	list2 = NULL;
	if (!list || !f || !del)
		return (NULL);
	while (list != NULL)
	{
		node = nc_list_new(f(list->content));
		if (!node)
		{
			nc_list_clear(&list, del);
			return (NULL);
		}
		nc_list_add_back(&list2, node);
		list = list->next;
	}
	return (list2);
}
